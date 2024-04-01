## Quicksort and Insertion Sort

## Overview

This project implements various versions of the Quicksort algorithm along with a hybrid approach combining Quicksort and Insertion Sort. The goal is to explore different pivoting strategies and compare their performance on sorting datasets of varying sizes.


## Features

- **Basic Quicksort Implementation**: Initial implementation of Quicksort without any optimizations.
- **Pivoting Strategies Exploration**: Extension of basic Quicksort to support different pivoting strategies: Last Element, Random Element, Median of Three.
- **Hybrid Quicksort and Insertion Sort**: Development of a hybrid sorting method based on a threshold value "k" to optimize performance.
- **Flexible Command Line Interface**: Users can specify dataset file, pivoting strategy, threshold "k", output file name, and verbose flag via command line arguments.
- **Comprehensive Testing and Evaluation**: Thorough testing and evaluation conducted on various datasets to assess correctness, efficiency, and scalability.


## Usage

1. Clone this repository to your local machine.
2. Navigate to the directory containing the `quicksort_insertionSort.cpp` file using the command line.
3. Compile the `quicksort_insertionSort.cpp` file using the provided shell command.
4. Run the compiled executable using the provided shell command with the required command line arguments:
    - `[DatasetFileName]`: Name of the dataset file.
    - `[PivotingStrategy]`: Pivoting strategy (l for Last Element, r for Random Element, m for Median of Three).
    - `[ThresholdK]`: Threshold value for switching between Quicksort and Insertion Sort.
    - `[OutputFileName]`: Name of the output file for sorted data.
    - `[VerboseFlag]`: Optional flag (v) for verbose output.
5. Review the generated output files for results.

## Testing and Evaluation

- Conduct thorough testing of the implemented algorithms on various datasets to assess correctness, efficiency, and scalability.
- Analyze and compare the performance of different pivoting strategies and the hybrid approach using appropriate metrics such as execution time and memory usage.


## Contributors
-Doğa Güneş Karadağ