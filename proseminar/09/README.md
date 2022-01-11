# Assignment 09, due January 18th, 2022

The goal of this assignment is to study vectorization.


## Exercise 1 (1.5 Point)

### Description

In this exercise, we will employ auto-vectorization of the compiler to increase the performance of a small program that computes a multiply-add operation on three vectors.

### Tasks

- Write a sequential program that computes `a[i] += b[i] * c[i]` for three `float` vectors `a`, `b`, and `c`. Enclose this computation in a loop such that it is repeated often enough to yield an overall execution time of a few seconds. I.e. your code should look like this:
```
for(int run = 0; run < repetitions; ++run) {
    for(int i = 0; i < size; ++i) {
        a[i] += b[i] * c[i];
    }
}
```
- Initialize the vectors with constant values and add some output that allows you to verify correct computation of the program for subsequent optimization steps. Compile this program on your local system using `-O1` and measure the execution time **of the computation only** for several problem sizes (=vector lengths). This sequential program is our baseline reference.
- Check which vectorization extensions your local CPU supports and try to use auto-vectorization in the compiler to vectorize the computation. Investigate which flag(s) you used and try to limit your compiler change to only enable vectorization but not any other optimizations. Measure the execution time for the same problem sizes as before and compute the respective speedups. What can you observe in terms of performance? Is the result still correct?
- Try to use assembly output and `perf` to verify the origin of any performance difference you might observe. `perf list` allows you to list generic events that can be counted on most platforms. `perf stat -e rUUEE` allows you to measure CPU-model-specific events, where - on Intel systems - `EE` is the so-called *event code* and `UU` is the so-called *unit mask* (also called *umask*). Worst case, if you can't find performance counters for your local CPU, you can also run this on LCC2 - for that purpose, a few event codes and unit masks for measuring vectorized instructions on LCC2's CPUs are given below. Note that these event codes are not necessarily the same for other CPU models:

| Name                            | Unit Mask | Event Code |
|---------------------------------|:---------:|:----------:|
| SIMD_INST_RETIRED.PACKED_SINGLE |    01     |     C7     |
| SIMD_INST_RETIRED.SCALAR_SINGLE |    02     |     C7     |
| SIMD_INST_RETIRED.PACKED_DOUBLE |    04     |     C7     |
| SIMD_INST_RETIRED.SCALAR_DOUBLE |    08     |     C7     |
| SIMD_INST_RETIRED.VECTOR        |    10     |     C7     |
| SIMD_INST_RETIRED.ANY           |    1F     |     C7     |

> In case you are interested: For further events relevant to the CPU type on LCC2 and short event descriptions, see Table 19-23 on pages 415-438 of the [Intel® 64 and IA-32 Architectures Software Developer’s Manual Volume 3B: System Programming Guide, Part 2](https://www.intel.com/content/www/us/en/architecture-and-technology/64-ia-32-architectures-software-developer-vol-3b-part-2-manual.html). It lists all events that can be counted with `perf`.

- Compare the effects of not explicitly aligning memory allocation at all or varying the alignment size for some reasonable numbers (e.g. powers of two between 2 and 64)
- Enter your best speedup along with the most significant setup properties (e.g. the specific vector extension used) into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p7EgZQW9D34pnLUofnEyMDOUJVF_FSFU_jB9eEECeqk/edit?usp=sharing.

## Exercise 2 (1.5 Point)

### Description

Instead of relying on the compiler to vectorize the code for us, we will do so manually in this exercise, using OpenMP.

### Tasks

- Vectorize your sequential program using OpenMP. Ensure proper alignment of the data. Do not use OpenMP's thread-based parallelism.
- Compile your OpenMP-vectorized code with `-O1` but without any compiler flags for auto-vectorization and compare its performance for your set of problem sizes to both the sequential version and the compiler-vectorized version. What can you observe? Is the result still correct?
- Try to verify any findings using assembly output or `perf` as described in Exercise 1.
- Repeat the sequential and OpenMP executions when changing the data type from `float` to `double`. What can you observe?
- Compare the effects of
  - not aligning memory allocation
  - aligning memory allocation but not adding any OpenMP alignment clauses
  - aligning memory allocation and adding OpenMP alignment clauses
  - varying the alignment size for some reasonable numbers (e.g. powers of two between 2 and 64)
- Compare this solution and its effects to Exercise 1.
- Enter your best speedup along with  with the most significant setup properties (e.g. the specific vector extension used) into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p7EgZQW9D34pnLUofnEyMDOUJVF_FSFU_jB9eEECeqk/edit?usp=sharing.