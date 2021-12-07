# Assignment 7, due December 14th 2021

The goal of this assignment is to investigate the performance and efficiency of different domain decomposition schemes.

## Exercise 1 (2 Points)

This exercise consists in comparing different domain decomposition schemes for a structured grid application and comparing their performance and speedup.

### Tasks

- Provide MPI implementations for the 3D heat stencil problem that each use slab, pole and cube domain decomposition respectively.
- Measure the speedup and efficiency for multiple problem and machine sizes as in previous exercises.
- Illustrate the data in appropriate figures and discuss them. What can you observe? Do you see any noticeable difference in performance between the different strategies?
- Add your best parallel wall time for each decomposition scheme for 64 cores and N=128 into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p7EgZQW9D34pnLUofnEyMDOUJVF_FSFU_jB9eEECeqk/edit?usp=sharing.

## Exercise 2 (1 Point)

This exercise consists in analyzing the performance of the decomposition schemes of Exercise 1 using a large-scale performance analysis tool.

### Tasks

- Use the ScoreP/Scalasca performance analysis tool suite to instrument your program. You can find the tools pre-installed on LCC2 at `/scratch/c703429/software/scalasca/` and `/scratch/c703429/software/scorep-7.1/`. For viewing the results, install Cube, a performance report explorer, locally (see "Supplementary packages for download" at https://www.scalasca.org/software/cube-4.x/download.html).
    1. compile with the `scorep` instrumentation tool via `scorep mpicc ...`
    2. run the application with `scalasca -analyze mpiexec ...`
    3. post-process the performance results using `scalasca -examine <report_directory>`. After postprocessing, it will try to open Cube on LCC2, which will fail with an error. You can safely ignore this error.
    4. retrieve the result files and examine them with Cube on your local machine
- Compare the three decomposition schemes of Exercise 1 using these tools. What information can you get from the performance report?
- Consider also running your application with tracing enabled. Details for that will be discussed in the next lecture.