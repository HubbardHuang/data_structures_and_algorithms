#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <cstddef>

/**
 * If there is no bug, open RELEASE.
 * If there is some errors that requires printing details, open DEBUG.
 * If you want to use some samples to test to find bugs, open TEST.
 */
// #define RELEASE
// #define DEBUG
#define TEST

#if (defined DEBUG || defined TEST)
#define PRINT
#endif

void InsertionSort(int nums[], size_t start_index, size_t end_index);

#endif