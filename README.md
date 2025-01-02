# 🚀 Parallel MergeSort

A high-performance, multi-threaded implementation of the Merge Sort algorithm that achieves up to **14.7x** speedup compared to sequential sorting.

## ✨ Features

- **Multi-threaded Implementation**: Leverages C++11 threading for parallel processing
- **Adaptive Threshold**: Automatically switches between parallel and sequential sorting based on input size
- **Thread Limiting**: Uses an atomic counter to ensure that the number of active threads does not exceed the system’s hardware concurrency, preventing thread oversubscription.
- **Memory Efficient**: In-place merging to minimize memory overhead
- **Thread Safety**: Mutex and atomic operations are employed to synchronize thread creation and ensure safe parallel execution.

## 🔧 Requirements

- C++11 compatible compiler
- pthread library

## 📦 Installation

1. Clone the repository:
```bash
git clone https://github.com/prem-charan/parallel-mergeSort.git
```

2. Navigate to the project directory:
```bash
cd parallel-mergeSort
```

## 🚀 Quick Start

### Method 1: Using Make (Recommended)

```bash
make
./bin/parallel_sort
```

### Method 2: Manual Compilation

```bash
cd src/app
g++ -std=c++11 main.cpp sorting/mergeSort.cpp sorting/parallelMergeSort.cpp -o parallel_sort -pthread
./parallel_sort
```

## 📊 Performance Benchmarks

| Array Size | Sequential (s) | Parallel (s) | Speedup |
|------------|---------------|--------------|---------|
| 10⁶        | 1.50          | 0.14        | 10.0x   |
| 10⁷        | 13.70         | 0.93        | 14.7x   |
| 10⁸        | 165.40        | 12.20       | 13.5x   |

> Benchmarks performed on an AMD Ryzen 5 5600H (6 cores) @ 3.3GHz, 8GB RAM

## 🏗️ Project Structure

```
parallel-mergeSort/
├── src/
│   ├── app/
│   │   ├── main.cpp
│   │   └── sorting/
│   │       ├── mergeSort.cpp
│   │       ├── mergeSort.hpp
│   │       ├── parallelMergeSort.cpp
│   │       └── parallelMergeSort.hpp
|   |__ parallel_sort
└── README.md
```

## 🔍 Implementation Details

The implementation uses a hybrid approach:
- For large arrays (>10,000 elements): Parallel processing with multiple threads
- For smaller arrays: Standard sequential sorting
- The number of threads is dynamically managed using std::atomic<int> for counting active threads and std::mutex to synchronize thread creation, avoiding resource exhaustion.
- Automatic thread pool sizing based on available hardware concurrency.

