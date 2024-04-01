# Heapsort Project

## Overview

The Heapsort Project implements various procedures related to heaps and priority queues, including MAX-HEAPIFY, BUILD-MAX-HEAP, HEAPSORT, priority queue operations, and d-ary heap operations. These procedures are crucial for maintaining heap properties, sorting arrays efficiently, and performing priority queue operations. The project includes implementations for both binary heaps and d-ary heaps.

## Features

- **MAX-HEAPIFY Procedure**: Implementation of the MAX-HEAPIFY procedure to maintain the max-heap property. Runs in O(log n) time.
- **BUILD-MAX-HEAP Procedure**: Extension to include the BUILD-MAX-HEAP procedure to produce a max-heap from an unordered input array. Runs in linear time.
- **HEAPSORT Procedure**: Implementation of the HEAPSORT procedure using MAX-HEAPIFY and BUILD-MAX-HEAP to sort an array in place.
- **Priority Queue Operations**: Integration of priority queue operations into the heap implementation, including MAX-HEAP-INSERT, HEAP-EXTRACT-MAX, HEAP-INCREASE-KEY, and HEAP-MAXIMUM. Examples demonstrating usage in real-world scenarios are included.
- **d-ary Heap Operations**: Implementation of operations specific to d-ary heaps, such as height calculation, EXTRACT-MAX, INSERT, and INCREASE-KEY. Time complexity analysis considering the parameters d and n provided for each operation.

## Usage

1. Clone this repository to your local machine.
2. Navigate to the directory containing the `Heapsort.cpp` file using the command line.
3. Compile the `Heapsort.cpp` file using the provided shell command.
4. Run the compiled executable using the provided shell command with the required command line arguments:
- `[DatasetFileName]`: Name of the dataset file.
- `[FunctionName]`: Name of the function to execute (e.g., max heapify, heapsort, max heap insert).
- `[OutputFileName]`: Name of the output file for sorted data.
- `[OptionalArguments]`: Optional arguments specific to the function (e.g., 'd5' for specifying the number of children in a d-ary heap).

## Testing

- Test the code on provided datasets to ensure correctness and efficiency.
- Adjust optional arguments to explore different scenarios and edge cases.

## Contributors

-Doğa Güneş Karadağ
