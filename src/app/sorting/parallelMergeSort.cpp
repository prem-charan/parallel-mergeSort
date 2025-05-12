#include "parallelMergeSort.hpp"
#include <algorithm>
#include <thread>

ParallelMergeSort::ParallelMergeSort(std::vector<int> *nums)
    : nums(nums)
{
}

ParallelMergeSort::~ParallelMergeSort() {}

void ParallelMergeSort::recursiveSort(int left, int right)
{
    const int THRESHOLD = 10000;

    if (right - left < THRESHOLD)
    {
        std::sort(nums->begin() + left, nums->begin() + right + 1);
        return;
    }

    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;

    bool spawn_thread_1 = false;
    bool spawn_thread_2 = false;

    {
        std::lock_guard<std::mutex> lock(thread_mutex);
        if (active_threads < std::thread::hardware_concurrency())
        {
            spawn_thread_1 = true;
            active_threads++;
        }
        if (active_threads < std::thread::hardware_concurrency())
        {
            spawn_thread_2 = true;
            active_threads++;
        }
    }

    std::thread thread_1, thread_2;

    if (spawn_thread_1)
    {
        thread_1 = std::thread([this, left, mid]
                               {
            this->recursiveSort(left, mid);
            active_threads--; });
    }
    else
    {
        this->recursiveSort(left, mid);
    }

    if (spawn_thread_2)
    {
        thread_2 = std::thread([this, mid, right]
                               {
            this->recursiveSort(mid + 1, right);
            active_threads--; });
    }
    else
    {
        this->recursiveSort(mid + 1, right);
    }

    if (thread_1.joinable())
        thread_1.join();
    if (thread_2.joinable())
        thread_2.join();


    std::vector<int> result;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if ((*nums)[i] <= (*nums)[j])
        {
            result.push_back((*nums)[i]);
            i++;
        }
        else
        {
            result.push_back((*nums)[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        result.push_back((*nums)[i]);
        i++;
    }

    while (j <= right)
    {
        result.push_back((*nums)[j]);
        j++;
    }

    for (int k = 0; k < result.size(); k++)
    {
        (*nums)[left + k] = result[k];
    }
}

void ParallelMergeSort::sort()
{
    if (nums->size() == 0)
    {
        exit(1);
    }

    std::thread thread_1([this]
                         { this->recursiveSort(0, nums->size() - 1); });
    thread_1.join();
}
