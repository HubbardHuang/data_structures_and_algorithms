#ifndef PARTITION_H
#define PARTITION_H

#include "range.h"
#include <cstddef>

Range<size_t> Partition(int nums[], size_t start_index, size_t end_index);

#endif