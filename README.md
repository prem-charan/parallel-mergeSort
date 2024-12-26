# parallel mergeSort using multi-threading

-> A high-performance implementation of the Merge Sort algorithm utilizing parallel processing and multi-threading capabilities to achieve optimal sorting performance.

-> Reduced sorting time by almost 10x times.

How to run the project:

Follow the commands below to run the project:

1. Clone this repository:
git clone https://github.com/prem-charan/parallel-mergeSort.git

2. Navigate to the project directory:
cd parallel-mergeSort

3. Go to src/app folder:
cd src/app

4. Compile the code:
g++ -std=c++11 main.cpp sorting/mergeSort.cpp sorting/parallelMergeSort.cpp -o parallel_sort -pthread

5. Run the executable:
./parallel_sort