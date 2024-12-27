# Parallel MergeSort Implementation using Multi-threading

A high-performance implementation of the Merge Sort algorithm that leverages parallel processing through multi-threading. This implementation achieves significant performance improvements, demonstrating more than 10x faster sorting times compared to traditional sequential merge sort.

#

Follow the commands below to run the project:

1. Clone this repository:
```bash
git clone https://github.com/prem-charan/parallel-mergeSort.git
```

2. Navigate to the project directory:
```bash
cd parallel-mergeSort
```

3. Go to src/app folder:
```bash
cd src/app
```

4. Compile the code:
```bash
g++ -std=c++11 main.cpp sorting/mergeSort.cpp sorting/parallelMergeSort.cpp -o parallel_sort -pthread
```

5. Run the executable:
```bash
./parallel_sort
```

##  Performance Benchmarks

| Array Size | Sequential Time | Parallel Time | Speedup |
|------------|----------------|---------------|---------|
| 10^6       | 1.5s           | 0.14s         | 10x     |
| 10^7       | 13.7s          | 0.93s         | 14.7x   |
| 10^8       | 165.4s         | 12.2s         | 13.5x   |