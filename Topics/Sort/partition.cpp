#include <algorithm>
#include <cstdio>
#include <ctime>
#include <vector>

#include "partition.h"

static size_t
GetPivotIndex(int nums[], size_t start_index, size_t end_index) {
    if (start_index > end_index) {
        std::swap(start_index, end_index);
    }
    if (start_index == end_index || end_index == 1 + start_index) {
        return start_index;
    }

    int mid_index = start_index + (end_index - start_index) / 2;
    int left_index = start_index;
    int right_index = end_index - 1;

    // make the leftmost less than the middle and the middle less than the rightmost
    if (nums[left_index] > nums[right_index]) {
        std::swap(nums[left_index], nums[right_index]);
    }
    if (nums[left_index] > nums[mid_index]) {
        std::swap(nums[left_index], nums[mid_index]);
    }
    if (nums[mid_index] > nums[right_index]) {
        std::swap(nums[mid_index], nums[right_index]);
    }

    // make the first element to be the privot
    std::swap(nums[left_index], nums[mid_index]);
    size_t pivot_index = left_index;
    return pivot_index;
}

#ifdef RELEASE
Range<size_t>
Partition(int nums[], size_t start_index, size_t end_index) {
    if (end_index == start_index) {
        return Range<size_t>(start_index, start_index);
    }
    if (end_index < start_index) {
        std::swap(end_index, start_index);
    }
    if (start_index + 1 == end_index) {
        return Range<size_t>(start_index, end_index);
    }

    size_t pivot_index = GetPivotIndex(nums, start_index, end_index);
    size_t left_index = start_index;
    size_t right_index = end_index;
    size_t left_pivot_range_end = pivot_index + 1;
    size_t right_pivot_range_start = end_index;

    // Divide the array into 4 parts:
    // [start_index, left_pivot_range_end): equal to pivot
    // [left_pivot_range_end, left_index): less than pivot
    // [left_index, right_pivot_range_start): greater than pivot
    // [right_pivot_range_start, end_index): equal to pivot
    while (true) {
        while (nums[++left_index] < nums[pivot_index]) {
        }
        while (nums[pivot_index] < nums[--right_index]) {
        }

        if (left_index < right_index) {
            std::swap(nums[left_index], nums[right_index]);
        } else {
            break;
        }

        // There is a special case:
        // If the variable "left_index" is equal to the variable "right_index",
        // and nums[left_index] is equal to nums[pivot_index],
        // the necessary swapping will be ignore.
        if (nums[left_index] == nums[pivot_index]) {
            std::swap(nums[left_index], nums[left_pivot_range_end++]);
        }
        if (nums[right_index] == nums[pivot_index]) {
            std::swap(nums[right_index], nums[--right_pivot_range_start]);
        }
    }

    size_t i, j;
    size_t pivot_range_begin, pivot_range_end;
    // Convert 4 parts into 3 parts:
    // [start_index, pivot_range_begin): less than pivot
    // [pivot_range_begin, pivot_range_end): equal to pivot
    // [pivot_range_end, end_index): greater than pivot
    i = start_index;
    // Handle the special case mentioned from line 73 to line 76
    j = nums[right_index] == nums[pivot_index] ? (right_index - 1) : right_index;
    for (; i < left_pivot_range_end && start_index <= j && j < end_index; i++, j--) {
        std::swap(nums[i], nums[j]);
    }

    pivot_range_begin = j + 1;
    i = right_index + 1;
    j = right_pivot_range_start;
    for (; j < end_index; i++, j++) {
        std::swap(nums[i], nums[j]);
    }
    pivot_range_end = i;

    return Range<size_t>(pivot_range_begin, pivot_range_end);
}
#endif

#ifdef PRINT
void
Print(int nums[], size_t start_index, size_t end_index) {
    for (size_t i = start_index; i < end_index; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
#endif

#ifdef PRINT
Range<size_t>
Partition(int nums[], size_t start_index, size_t end_index) {
    if (end_index == start_index) {
        return Range<size_t>(start_index, start_index);
    }
    if (end_index < start_index) {
        std::swap(end_index, start_index);
    }
    if (start_index + 1 == end_index) {
        return Range<size_t>(start_index, end_index);
    }

    size_t pivot_index = GetPivotIndex(nums, start_index, end_index);
    size_t left_index = start_index;
    size_t right_index = end_index;
#ifdef PRINT
    printf("pivot = %d\n", nums[pivot_index]);
#endif
    size_t left_pivot_range_end = pivot_index + 1;
    size_t right_pivot_range_start = end_index;

    // Divide the array into 4 parts:
    // [start_index, left_pivot_range_end): equal to pivot
    // [left_pivot_range_end, left_index): less than pivot
    // [left_index, right_pivot_range_start): greater than pivot
    // [right_pivot_range_start, end_index): equal to pivot
    while (true) {
        while (nums[++left_index] < nums[pivot_index]) {
        }
        while (nums[pivot_index] < nums[--right_index]) {
        }

        if (left_index < right_index) {
            std::swap(nums[left_index], nums[right_index]);
        } else {
            break;
        }

        // There is a special case:
        // If the variable "left_index" is equal to the variable "right_index",
        // and nums[left_index] is equal to nums[pivot_index],
        // the necessary swapping will be ignore.
        if (nums[left_index] == nums[pivot_index]) {
            std::swap(nums[left_index], nums[left_pivot_range_end++]);
        }
        if (nums[right_index] == nums[pivot_index]) {
            std::swap(nums[right_index], nums[--right_pivot_range_start]);
        }
    }
#ifdef DEBUG
    printf("Before Convert:\n");
    printf("left_index = %zd, right_index = %zd\n", left_index, right_index);
    Print(nums, start_index, end_index);
#endif

    size_t i, j;
    size_t pivot_range_begin, pivot_range_end;
    // Convert 4 parts into 3 parts:
    // [start_index, pivot_range_begin): less than pivot
    // [pivot_range_begin, pivot_range_end): equal to pivot
    // [pivot_range_end, end_index): greater than pivot
    i = start_index;
    // Handle the special case mentioned from line 73 to line 76
    j = nums[right_index] == nums[pivot_index] ? (right_index - 1) : right_index;
    for (; i < left_pivot_range_end && start_index <= j && j < end_index; i++, j--) {
        std::swap(nums[i], nums[j]);
    }
#ifdef DEBUG
    printf("Left: i = %zd, j = %zd\n", i, j);
#endif
    pivot_range_begin = j + 1;
    i = right_index + 1;
    j = right_pivot_range_start;
    for (; j < end_index; i++, j++) {
        std::swap(nums[i], nums[j]);
    }
#ifdef DEBUG
    printf("Right: i = %zd, j = %zd\n", i, j);
#endif
    pivot_range_end = i;

    return Range<size_t>(pivot_range_begin, pivot_range_end);
}
#endif

#ifdef TEST
size_t
GetRandomNum(size_t min, size_t max) {
    return rand() % (max - min + 1) + min;
}
void
TestPartition(size_t sample_count) {
    srand(static_cast<unsigned>(time(nullptr)));
    for (size_t i = 0; i < sample_count; i++) {
        size_t length = GetRandomNum(0, 20);
        int* sample = new int[length];
        for (size_t j = 0; j < length; j++) {
            sample[j] = GetRandomNum(0, 15);
        }
        printf("------------\n");
        printf("Before partition:\n");
        Print(sample, 0, length);
        Range<size_t> result = Partition(sample, 0, length);
        printf("After partition: \n");
        Print(sample, 0, length);
        printf("result: [%zd, %zd)---%d, %d\n", result.begin_, result.end_,
               sample[result.begin_], sample[result.end_ - 1]);
        delete[] sample;
    }
}
#endif

#ifdef PRINT
int
main(void) {
#ifdef DEBUG
    int nums[] = { 14, 1, 2, 10, 11, 12, 6, 3, 2, 12, 10, 14, 7, 9, 14 };
    Range<size_t> result = Partition(nums, 0, 15);
    printf("After partition: \n");
    Print(nums, 0, 15);
    printf("result: [%zd, %zd)---%d, %d\n", result.begin_, result.end_,
           nums[result.begin_], nums[result.end_ - 1]);
#endif
#ifdef TEST
    TestPartition(10);
#endif
    return 0;
}
#endif