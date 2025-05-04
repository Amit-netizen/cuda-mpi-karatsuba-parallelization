# 🚀 **High-Performance Parallel Karatsuba Multiplication**

This repository optimizes the **Karatsuba algorithm** for large integer multiplication using **CUDA** for GPU parallelism and **MPI** for distributed parallelism. By parallelizing computations on **NVIDIA GPUs** with CUDA, we achieved a **32.32× speedup** (from 20.79ms to 0.691ms). With **MPI**, we achieved a **5.02× speedup** (from 26.333ms to 5.241ms) for distributed execution on multi-core CPU clusters.

---

## 📝 **Project Structure**

The project contains the following files:

### 1. **RandomNumberGenerator_X.c & RandomNumberGenerator_Y.c**
   - Generates **100,000 random 8-digit numbers**.
   - Saves the generated numbers to two text files: `X_100000.txt` and `Y_100000.txt`.

### 2. **Seq_Karatsuba_100000.c**
   - Sequential implementation of the **Karatsuba algorithm** for multiplying large integers.

### 3. **CUDA_Karatsuba_100000.cu**
   - **CUDA** implementation of the **Karatsuba algorithm** for **GPU acceleration**.

### 4. **MPI_Karatsuba_100000.c**
   - **MPI**-based distributed parallel implementation for Karatsuba multiplication across **multiple CPU nodes**.

---

## 🔧 **Requirements**

### System Requirements:
- **CUDA-enabled NVIDIA GPU** (for CUDA implementation)
- **MPI** (for MPI implementation)
- **C Compiler** (for compiling the code)
- **CUDA Toolkit** (for compiling CUDA code)
- **OpenMPI** (for MPI code)

### Install Dependencies:
- **CUDA Toolkit**: [Download from NVIDIA](https://developer.nvidia.com/cuda-toolkit)
- **OpenMPI**: Install from the [OpenMPI website](https://www.open-mpi.org/) or use package managers like `apt` or `brew` for Linux/Mac.

---

## ⚡ **Compilation and Execution**

### 1. **CUDA Code Compilation:**
gcc karatsuba_seq.c -o karatsuba_seq
./karatsuba_seq

### 2. **CUDA Code Compilation:**
```bash
nvcc karatsuba_cuda.cu -o karatsuba_cuda
./karatsuba_cuda

### 3. **MPI Code Compilation:**
```bash
mpicc karatsuba_mpi.c -o karatsuba_mpi
mpirun -np <num_processes> ./karatsuba_mpi
