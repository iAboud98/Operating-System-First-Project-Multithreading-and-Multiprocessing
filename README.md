# Word Frequency Analysis Using Multiple Approaches

This repository contains the implementation of a **Word Frequency Analysis** program, developed as part of the ENCS3390: Operating System Concepts course (Fall 2024). The program processes the `enwik8` dataset to identify the top 10 most frequent words, comparing performance across three approaches: naive, multiprocessing, and multithreading.

## Features

1. **Naive Approach**:
   - Single-threaded implementation.
   - Processes the dataset sequentially.

2. **Multiprocessing Approach**:
   - Utilizes multiple child processes to divide the workload.
   - Supports configurations for 2, 4, 6, and 8 child processes.

3. **Multithreading Approach**:
   - Utilizes multiple threads to divide the workload.
   - Supports configurations for 2, 4, 6, and 8 threads.

4. **Performance Metrics**:
   - Measures and compares execution time for each approach.
   - Evaluates the impact of parallelism on performance.

## Dataset

The `enwik8` dataset is used for this project and can be accessed from [Hugging Face](https://huggingface.co/datasets/LTCB/enwik8).

## Simulation Details

1. **Execution Environment**:
   - Requires a system with at least **4 cores**.
   - Virtual machines should allocate a minimum of 4 cores for accurate results.

2. **Performance Analysis**:
   - Measures execution time for each approach.
   - Includes an analysis of serial and parallel sections using **Amdahl's Law**.
   - Compares the impact of varying numbers of threads and processes.

## Output

 **Top 10 Frequent Words**:
   - A list of the most frequent words in the dataset.


## Authors and Acknowledgments

This project was developed as part of the ENCS3390 course at the Department of Electrical & Computer Engineering.

---
