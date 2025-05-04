# 🚀 High-Performance Parallel Karatsuba Multiplication with CUDA and MPI

[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![CUDA](https://img.shields.io/badge/CUDA-NVIDIA-brightgreen?style=flat&logo=nvidia)](https://developer.nvidia.com/cuda-toolkit)
[![MPI](https://img.shields.io/badge/MPI-Parallel%20Computing-blue)](https://www.mpi-forum.org/)
[![C](https://img.shields.io/badge/C-ISO%20C11-lightgrey?style=flat&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C11)

This repository explores and implements parallelized versions of the **Karatsuba algorithm** for efficient multiplication of large integers, leveraging the power of **NVIDIA GPUs** with **CUDA** and distributed computing across **CPU clusters** using **MPI (Message Passing Interface)**.

## 🎯 Project Goals

* To implement the Karatsuba algorithm in sequential C, CUDA, and MPI.
* To demonstrate the performance benefits of GPU acceleration using CUDA for large integer multiplication.
* To showcase the scalability of distributed parallel computing using MPI for the Karatsuba algorithm across multiple CPU cores/nodes.
* To provide clear and well-documented implementations for educational and comparative purposes.

## 📂 Repository Structure

The project contains the following files:

1.  **`RandomNumberGenerator_X.c` & `RandomNumberGenerator_Y.c`**:

    * Generates **100,000 random 8-digit numbers** using the `rand()` function with a modulo operation and offset to ensure numbers are within the 10000000 to 99999999 range:

        ```c
        int random_number = rand() % 90000000 + 10000000;
        ```

    * Saves the generated numbers into `X_100000.txt` and `Y_100000.txt` respectively, which serve as input for the multiplication algorithms. [cite: 1]

2.  **`Seq_Karatsuba_100000.c`**:

    * Implements the **sequential version** of the Karatsuba algorithm in C. This serves as a baseline for performance comparison.

3.  **`CUDA_Karatsuba_100000.cu`**:

    * Implements the **Karatsuba algorithm using CUDA** to leverage the parallel processing capabilities of NVIDIA GPUs. This version aims for significant speedups compared to the sequential implementation for large inputs.

4.  **`MPI_Karatsuba_100000.c`**:

    * Implements the **Karatsuba algorithm using MPI** for distributed parallel execution across multiple CPU cores or nodes. This allows for tackling even larger multiplication problems by distributing the workload.

## ⚙️ Requirements

### Hardware:

* **CUDA Implementation:** A **CUDA-enabled NVIDIA GPU** is required to compile and run the CUDA version.
* **MPI Implementation:** A multi-core CPU system or a cluster of machines with **MPI installed** is necessary for distributed execution.

### Software:

* **C Compiler:** A standard C compiler (like GCC) is needed for compiling the sequential and MPI versions.
* **CUDA Toolkit:** The **NVIDIA CUDA Toolkit** must be installed to compile the `.cu` files. Ensure it's compatible with your GPU and operating system. ([Download from NVIDIA](https://developer.nvidia.com/cuda-toolkit))
* **MPI Implementation:** An **MPI library** (such as Open MPI or MPICH) needs to be installed on your system. ([Open MPI Website](https://www.open-mpi.org/))

### Installation (Dependencies):

* **CUDA Toolkit:** Follow the installation instructions provided by NVIDIA for your specific platform.
* **Open MPI (Example for Debian/Ubuntu):**

    ```bash
    sudo apt update
    sudo apt install libopenmpi-dev openmpi-bin
    ```

* **Open MPI (Example for macOS with Homebrew):**

    ```bash
    brew install open-mpi
    ```

## 🚀 Compilation and Execution

The compilation and execution instructions are as follows:

### 1. Sequential C Implementation:

* **Compilation:**

    ```bash
    gcc Seq_Karatsuba_100000.c -o karatsuba_seq
    ```

    This command compiles the C source file `Seq_Karatsuba_100000.c` and creates an executable named `karatsuba_seq`.
* **Execution:**

    ```bash
    ./karatsuba_seq
    ```

    This command runs the compiled sequential Karatsuba program.

### 2. CUDA Implementation:

* **Compilation:**

    ```bash
    nvcc CUDA_Karatsuba_100000.cu -o karatsuba_cuda
    ```

    This command compiles the CUDA source file `CUDA_Karatsuba_100000.cu` using the NVIDIA CUDA Compiler (`nvcc`) and creates an executable named `karatsuba_cuda`.
* **Execution:**

    ```bash
    ./karatsuba_cuda
    ```

    This command executes the compiled CUDA Karatsuba program on your CUDA-enabled GPU.

### 3. MPI Implementation:

* **Compilation:**

    ```bash
    mpicc MPI_Karatsuba_100000.c -o karatsuba_mpi
    ```

    This command compiles the MPI-enabled C source file `MPI_Karatsuba_100000.c` using the MPI C compiler wrapper (`mpicc`) and creates an executable named `karatsuba_mpi`.
* **Execution:**

    ```bash
    mpirun -np <num_processes> ./karatsuba_mpi
    ```

    This command executes the compiled MPI Karatsuba program using `mpirun`. Replace `<num_processes>` with the number of parallel processes you want to run. For example, `mpirun -np 4 ./karatsuba_mpi` will run the program on 4 processes.

## 📊 Performance Results

The following tables and descriptions summarize the performance results obtained from the experiments.

### MPI Parallelization Results

| S.No. | Sequential (milliseconds) | MPI (milliseconds) | Speedup |
| ----- | ------------------------- | ------------------ | ------- |
| 1     | 52.131                  | 6.066              | 8.6     |
| 2     | 17.146                  | 5.719              | 3.0     |
| 3     | 32.855                  | 5.355              | 6.1     |
| 4     | 14.758                  | 3.711              | 4.0     |
| 5     | 14.779                  | 5.355              | 2.7     |

* **MPI Speedup:** MPI implementation achieved speedups ranging from 2.7 to 8.6 times compared to the sequential version, demonstrating the benefits of parallel processing on a CPU. [cite: 2]

### CUDA Parallelization Results

| S.No. | Sequential (milliseconds) | CUDA (milliseconds) | Speedup |
| ----- | ------------------------- | ------------------- | ------- |
| 1     | 19.773                  | 0.671               | 29.467  |
| 2     | 20.719                  | 0.723               | 28.656  |
| 3     | 21.304                  | 0.692               | 30.786  |
| 4     | 20.916                  | 0.712               | 29.376  |
| 5     | 21.235                  | 0.657               | 32.321  |

* **CUDA Speedup:** The CUDA implementation showed significantly higher speedups, ranging from approximately 28 to 32 times faster than the sequential version, highlighting the massive parallelism offered by GPUs. [cite: 5]

### Graphical Results (Description)

The document mentions "Fig 6: Graphical Results of 100000 number dataset, by taking the number of iterations in the X coordinate and time (milliseconds) in the Y coordinate." [cite: 3, 6]

* This graph visually represents the performance comparison, likely showing the time taken for each implementation (Sequential, MPI, CUDA) across multiple iterations.
* The X-axis represents the iteration number, and the Y-axis represents the execution time in milliseconds.
* It would typically demonstrate that CUDA has the lowest execution time, followed by MPI, with Sequential having the highest execution time.

## 📝 Notes

* The input numbers for all implementations are generated by `RandomNumberGenerator_X.c` and `RandomNumberGenerator_Y.c`. Ensure these are compiled and run first to create the input files `X_100000.txt` and `Y_100000.txt`. [cite: 1]
* The performance results mentioned are specific to the hardware and input size used during testing. Your results may vary.
* Experiment with different numbers of processes for the MPI implementation (`-np` flag) to observe the scalability on your system.
* Ensure that your NVIDIA drivers are compatible with the CUDA Toolkit version you are using.

## 🤝 Contributing

Contributions to this project are welcome! If you have suggestions for improvements, bug fixes, or new features, feel free to open an issue or submit a pull request. Please follow standard Git contribution workflows.

## 📜 License

This project is licensed under the **MIT License**. See the `LICENSE` file for more details.

## 🙏 Acknowledgements

* We acknowledge the work of the original authors of the Karatsuba algorithm.
* We appreciate the developers of NVIDIA CUDA and the MPI standard for providing powerful tools for parallel computing.

---
