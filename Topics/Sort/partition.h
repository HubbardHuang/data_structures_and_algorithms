#ifndef PARTITION_H
#define PARTITION_H

#include "range.h"
#include <cstddef>

// If there is no bug, open this.
#define RELEASE

// If there is some errors that requires printing details, open it.
// #define DEBUG

// If you want to use some samples to test to find bugs, open it.
// #define TEST

#if (defined DEBUG || defined TEST)
#define PRINT
#endif

Range<size_t> Partition(int nums[], size_t start_index, size_t end_index);

#endif