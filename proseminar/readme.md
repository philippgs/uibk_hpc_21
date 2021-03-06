# 703309 PS High-Performance Computing (Winter Semester 2021/22)

This repository contains material required to complete exercises for the
High-Performance Computing lab in the 2021/2022 winter semester, including assignment
sheets and any associated materials. Note that some of this material is based
on previous years.

## Topics

Generally, topics discussed here include

- distributed memory parallelization using MPI
- parallel programming concepts
- performance-oriented programming
- proper experiment orchestration and benchmarking
- parallel programming tools

## Schedule

This schedule gives you an overview of the topics we will discuss on each date.
It will be updated continuously throughout the semester. Note that exercises
associated with a given date are to be discussed on that day, i.e., solutions
for that assignment have to be handed in via OLAT by 9:00 on Tuesday.

| Date       | Assignment | Topics                                                      |
| ---------- | ---------- | ----------------------------------------------------------- |
| 2021-10-12 | -          | Administrative matters, introduction to LCC2                |
| 2021-10-19 | [1](01)    | SLURM Job Submission, basic cluster setup and measurements  |
| 2021-11-09 | [2](02)    | Basic parallelization with MPI                              |
| 2021-11-16 | [3](03)    | 2D/3D heat stencil: Virtual topologies, derived data types  |
| 2021-11-23 | [4](04)    | 2D/3D heat stencil: latency hiding, hybrid parallelism      |
| 2021-11-30 | [5](05)    | 3D n-body: sequential version and parallelization planning  |
| 2021-12-07 | [6](06)    | 3D n-body: parallelization, optimization, load balancing    |
| 2021-12-14 | [7](07)    | 3D heat stencil: domain decomposition, performance analysis |
| 2022-01-11 | [8](08)    | Basic parallelization with Chapel, monte carlo PI           |
| 2022-01-18 | [9](09)    | Vectorization                                               |
| 2022-01-25 | [10](10)   | Heat stencil porting to SYCL                                |


## Handing in and Presenting Solutions

All the material required by the given tasks (e.g. code, figures, etc...) must be 
part of the solution that is handed in. Your experiments should be reproducible and 
comparable to your own measurements using the solution materials that you hand in.

**Please run any benchmarks or heavy CPU loads only on the compute nodes, not on the login node.**
If you want to do some interactive experimentation, use an *interactive job*. Make 
sure to stop any interactive jobs once you are done.


### Coding Guidelines

All programming exercises are conducted in C or C++.

Your code should always compile without warnings, when passing the flags 
`-Wall -Wextra -Werror -std=gnu11`. Error handling is your discretion, but 
wherever you do or do not include error handling you need to be able to justify 
it.

Make sure your code is properly formatted using either your IDE/Text editor of
choice, or by using a tool such as `clang-format`. You can find an example
[.clang-format](.clang-format) file in this repository. **Failure to
consistently format code may result in lower scores.**

Try to write _self-documenting code_ by choosing descriptive variable and
function names. While you may want to add comments to certain sections of your
code, try to avoid trivial comments such as `fopen(...); // open file`. The best
source code comments are the ones you do NOT need to write. **All names and
comments should be written in English**.

Finally, all submitted code must be accompanied by a GNU Makefile. That is, your
solution must be able to be compiled with a single call to `make`. You can find
an example Makefile and more information [here](example_makefile).
