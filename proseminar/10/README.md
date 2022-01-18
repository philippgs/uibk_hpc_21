# Assignment 10, due January 25th, 2022

The goal of this assignment is to use SYCL, a programming model designed for accelerators

## Exercise 1 (3 Points)

### Description

In this exercise, we will port the heat stencil application of Assignment 02 to use SYCL, therefore enabling the use of accelerators. Note that while LCC2 is not equipped with accelerators, we can still explore the API and use the OpenMP backend of hipSYCL (one of several SYCL implementations) to run on the CPUs.

### Tasks

- Convert the 1D heat stencil example code of Assignment 02 to a C++ application. You don't need to re-write the entire code (e.g. you can leave `printf` calls) but one should at least be able to compile the code as C++ without warnings.
- Rewrite the computation to happen inside a SYCL kernel. In order to speed up your setup time, you can compile the code with `syclcc` of hipSYCL, provided pre-installed at `/scratch/c703429/software/hipsycl-develop`. Note that you might need to have the `gcc/10.3.0` module loaded.
- Benchmark your SYCL application on LCC2 with various problem sizes and numbers of threads. What can you observe?
- If you feel like it, try to install hipSYCL or another SYCL implementation (e.g. Codeplay's ComputeCPP or Intel's DPC++) locally and try to use any GPUs. In case you attempt this, first do your research to ensure your hardware/software platform is supported! Report any issues/findings.
