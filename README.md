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
    * Generates **100,000 random 8-digit numbers**.
    * Saves the generated numbers into `X_100000.txt` and `Y_100000.txt` respectively, which serve as input for the multiplication algorithms.

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

## 📊 Performance Results (as mentioned in the original README)

* **CUDA Parallelization:** Achieved a **32.32× speedup** (from 20.79ms to 0.691ms) compared to the sequential implementation on the given input size.
* **MPI Parallelization:** Achieved a **5.02× speedup** (from 26.333ms to 5.241ms) when executed on multiple CPU cores. The actual speedup may vary depending on the number of processes and the underlying hardware.

## 📝 Notes

* The input numbers for all implementations are generated by `RandomNumberGenerator_X.c` and `RandomNumberGenerator_Y.c`. Ensure these are compiled and run first to create the input files.
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
