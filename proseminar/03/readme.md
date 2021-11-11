# Assignment 3, due November 16th 2021

The goal of this assignment is to extend the heat stencil application and measure its performance.

## Exercise 1 (2 Points)

This exercise consists in extending the heat stencil application of Assignment 2 to two and three dimensions.

### Tasks

- Extend the heat stencil application to the two- and three-dimensional cases and name them `heat_stencil_2D` and `heat_stencil_3D`.
- Provide a sequential and an MPI implementation, and for the latter make use of MPI's virtual topologies and derived data types features where applicable. Try to make your implementation as efficient as possible, also with regard to code readability.
- Run your programs with multiple problem and machine sizes.
- How can you verify the correctness of your applications?

## Exercise 2 (1 Point)

This exercise consists in measuring all heat stencil variants (1D, 2D and 3D) to get a grasp of their performance behavior.

### Tasks

- Measure the speedup and efficiency of all three stencil codes for varying problem and machine sizes/mappings. Consider using strong scalability, weak scalability, or both. Justify your choice.
- Illustrate the data in appropriate figures and discuss them. What can you observe?
- Measure and illustrate at least one domain-specific and one domain-inspecific performance metric. What can you observe?
- Insert the (absolute) scalability for 64 cores for a problem size of your choice into the comparison spreadsheet: https://docs.google.com/spreadsheets/d/1p7EgZQW9D34pnLUofnEyMDOUJVF_FSFU_jB9eEECeqk/edit?usp=sharing