# cuda-mpi-karatsuba-parallelization
This project optimizes the Karatsuba algorithm for large integer multiplication using CUDA and MPI. By parallelizing computations on NVIDIA GPUs with CUDA, we achieved a 32.32× speedup (from 20.79ms to 0.691ms). With MPI, we achieved a 5.02× speedup (from 26.333ms to 5.241ms) for distributed execution on multi-core CPU clusters.


🚀 High-Performance Parallel Karatsuba Multiplication
This repository implements the Karatsuba algorithm for large integer multiplication, with optimizations using CUDA for GPU parallelism and MPI for distributed parallelism. The project demonstrates significant performance improvements by parallelizing the recursive multiplication steps, achieving speedups in both sequential and parallel executions.

📝 Project Structure
random_number_generator.c: Generates 100,000 random 8-digit numbers and saves them to X_5000.txt and Y_5000.txt.

karatsuba_seq.c: Sequential implementation of the Karatsuba algorithm for multiplying large integers.

karatsuba_cuda.cu: CUDA implementation of the Karatsuba algorithm for GPU acceleration.

karatsuba_mpi.c: MPI-based distributed parallel implementation for Karatsuba multiplication across multiple CPU nodes.

🔧 Requirements
System Requirements
CUDA-enabled NVIDIA GPU (for CUDA implementation)

MPI (for MPI implementation)

C Compiler (for compiling the code)

CUDA Toolkit (for compiling CUDA code)

OpenMPI (for MPI code)

Install Dependencies
CUDA Toolkit: Download from NVIDIA

OpenMPI: Install from OpenMPI website or use package managers like apt or brew for Linux/Mac.
