# Assignment 4, due November 23rd 2021

The goal of this assignment is to optimize the heat stencil application.

## Exercise 1 (3 Points)

This exercise consists in optimizing the heat stencil application of Assignment 2 and 3 to use non-blocking communication.

### Tasks

- Provide an MPI implementation for the 2D and 3D heat stencil that uses non-blocking communication. You can choose between two-sided non-blocking communication or one-sided communication.
- Structure your program such that you 1) start a non-blocking ghost cell exchange, 2) compute the inner cells which do not require the result of the ghost cell exchange, and 3) block until the ghost cell exchange in 1) has been finished and the remaining cells can be computed.
- Run your programs with multiple problem and machine sizes.
- Insert the improvement for 64 cores over blocking communication for a problem size of your choice into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p7EgZQW9D34pnLUofnEyMDOUJVF_FSFU_jB9eEECeqk/edit?usp=sharing

## Exercise 2 (2 Bonus points)

This exercise consists in using hybrid parallelization instead of MPI-only.

### Tasks

- Choose one of the 2D or 3D heat stencil applications and provide a hybrid parallelization using MPI+OpenMP. Either use a single MPI rank per shared-memory node or a single MPI rank per CPU. Beyond that, use OpenMP to use all remaining cores of the node.
- Run your programs with multiple problem and machine sizes.
- Compare the performance to your MPI-only implementation for the same machine size and problem size. Which version is faster?
- Insert the relative performance over MPI-only on 64 cores for a problem size of your choice into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p7EgZQW9D34pnLUofnEyMDOUJVF_FSFU_jB9eEECeqk/edit?usp=sharing