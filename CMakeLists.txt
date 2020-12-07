cmake_minimum_required(VERSION 3.17)
project(c_test C)

set(CMAKE_C_STANDARD 99)

add_executable(c_test main.c algorithm/recursive-algorithm/divide-and-conquer-algorithm/mergequeue.h algorithm/recursive-algorithm/divide-and-conquer-algorithm/speedqueue.h algorithm/recursive-algorithm/divide-and-conquer-algorithm/rankselect.h algorithm/recursive-algorithm/divide-and-conquer-algorithm/routedate.h algorithm/recursive-algorithm/dynamic-planning/mulit-matrix.h algorithm/recursive-algorithm/dynamic-planning/longest-common-subsequence.h algorithm/recursive-algorithm/dynamic-planning/zero-one-knapsack-problem.h algorithm/recursive-algorithm/dynamic-planning/optima-binary-search-tree.h "algorithm/greedy-algorithm/event-scheduling-issues.h" "algorithm/greedy-algorithm/backpack-problem .h")