# 🚀 **High-Performance Parallel Karatsuba Multiplication**

This repository optimizes the **Karatsuba algorithm** for large integer multiplication using **CUDA** for GPU parallelism and **MPI** for distributed parallelism. By parallelizing computations on **NVIDIA GPUs** with CUDA, we achieved a **32.32× speedup** (from 20.79ms to 0.691ms). With **MPI**, we achieved a **5.02× speedup** (from 26.333ms to 5.241ms) for distributed execution on multi-core CPU clusters.

---

## 📝 **Project Structure**

The project contains the following files:

### 1. **Random Number Generation**
   - **RandomNumberGenerator\_X.c & RandomNumberGenerator\_Y.c**
     - Generates **100,000 random 8-digit numbers**.
     - Saves the generated numbers to two text files: `X_100000.txt` and `Y_100000.txt`.

### 2. **Karatsuba Implementations**
   - **Seq\_Karatsuba\_100000.c**
     - Sequential implementation of the **Karatsuba algorithm** for multiplying large integers.
   - **CUDA\_Karatsuba\_100000.cu**
     - **CUDA** implementation of the **Karatsuba algorithm** for **GPU acceleration**.
   - **MPI\_Karatsuba\_100000.c**
     - **MPI**-based distributed parallel implementation for Karatsuba multiplication across **multiple CPU nodes**.

---

## 🔧 **Requirements**

### System Requirements:
- **CUDA-enabled NVIDIA GPU** (for CUDA implementation)
- **MPI** (for MPI implementation)
- **C Compiler** (for compiling C code)
- **CUDA Toolkit** (for compiling CUDA code)
- **OpenMPI** (for MPI code)

### Install Dependencies:
- **CUDA Toolkit**: [Download from NVIDIA](https://developer.nvidia.com/cuda-toolkit)
- **OpenMPI**: Install from the [OpenMPI website](https://www.open-mpi.org/) or use package managers like `apt` or `brew` for Linux/Mac.

---

## ⚡ **Compilation and Execution**

### 1. **Sequential C Implementation:**

* **Compilation:**
    ```bash
    gcc Seq_Karatsuba_100000.c -o karatsuba_seq
    ```
    This command compiles the sequential C implementation and creates an executable named `karatsuba_seq`.

* **Execution:**
    ```bash
    ./karatsuba_seq
    ```
    This command runs the compiled sequential Karatsuba program.

### 2. **CUDA Implementation:**

* **Compilation:**
    ```bash
    nvcc CUDA_Karatsuba_100000.cu -o karatsuba_cuda
    ```
    This command compiles the CUDA implementation using the NVIDIA CUDA Compiler (`nvcc`) and creates an executable named `karatsuba_cuda`.

* **Execution:**
    ```bash
    ./karatsuba_cuda
    ```
    This command executes the compiled CUDA Karatsuba program on a system with a compatible NVIDIA GPU.

### 3. **MPI Implementation:**

* **Compilation:**
    ```bash
    mpicc MPI_Karatsuba_100000.c -o karatsuba_mpi
    ```
    This command compiles the MPI implementation using the MPI C compiler wrapper (`mpicc`) and creates an executable named `karatsuba_mpi`.

* **Execution:**
    ```bash
    mpirun -np <num_processes> ./karatsuba_mpi
    ```
    This command executes the compiled MPI Karatsuba program using `mpirun`. Replace `<num_processes>` with the desired number of parallel processes.
