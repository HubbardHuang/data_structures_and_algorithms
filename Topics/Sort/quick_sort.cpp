#include <algorithm>
#include <cstdio>
#include <ctime>
#include <stack>
#include <vector>

#include "insertion_sort.h"
#include "partition.h"
#include "quick_sort.h"
#include "range.h"

/**
 * If there is no bug, open RELEASE.
 * If there is some errors that requires printing details, open DEBUG.
 * If you want to use some samples to test to find bugs, open TEST.
 */
#define RELEASE
// #define DEBUG
// #define TEST

#if (defined DEBUG || defined TEST)
#define PRINT
#endif

// #define RECURSION
// #define BOTH_RECURSION_AND_ITERATION
#define ITERATION

#if defined RECURSION
void
QuickSort(int nums[], size_t start_index, size_t end_index) {
    if (start_index > end_index) {
        std::swap(start_index, end_index);
    }
    if (start_index + 1 == end_index || start_index == end_index) {
        return;
    }

    if (start_index + 10 >= end_index) {
        InsertionSort(nums, start_index, end_index);
    } else {
        Range<size_t> pivot_range = Partition(nums, start_index, end_index);
        QuickSort(nums, start_index, pivot_range.begin_);
        QuickSort(nums, pivot_range.end_, end_index);
    }
}
#elif defined BOTH_RECURSION_AND_ITERATION
void
QuickSort(int nums[], size_t start_index, size_t end_index) {
    if (start_index > end_index) {
        std::swap(start_index, end_index);
    }
    if (start_index + 1 == end_index || start_index == end_index) {
        return;
    }

    while (start_index < end_index) {
        if (start_index + 10 >= end_index) {
            InsertionSort(nums, start_index, end_index);
            start_index = end_index;
        } else {
            Range<size_t> pivot_range = Partition(nums, start_index, end_index);
            QuickSort(nums, start_index, pivot_range.begin_);
            start_index = pivot_range.end_;
        }
    }
}
#elif defined ITERATION
void
QuickSort(int nums[], size_t start_index, size_t end_index) {
    if (start_index > end_index) {
        std::swap(start_index, end_index);
    }
    if (start_index + 1 == end_index || start_index == end_index) {
        return;
    }

    std::stack<Range<size_t>> range_stack;
    range_stack.push(Range<size_t>(start_index, end_index));

    while (!range_stack.empty()) {
        Range<size_t> range = range_stack.top();
        range_stack.pop();
        if (range.begin_ + 1 == range.end_ || range.end_ == range.begin_) {
            continue;
        }
        if (range.begin_ + 10 >= range.end_) {
            InsertionSort(nums, range.begin_, range.end_);
        } else {
            Range<size_t> pivot_range = Partition(nums, range.begin_, range.end_);
            range_stack.push(Range<size_t>(range.begin_, pivot_range.begin_));
            range_stack.push(Range<size_t>(pivot_range.end_, range.end_));
        }
    }
}
#endif

/*********************************************/
#ifdef PRINT
void
Print(int nums[], size_t start_index, size_t end_index) {
    for (size_t i = start_index; i < end_index; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
#endif

#ifdef TEST
size_t
GetRandomNum(size_t min, size_t max) {
    return rand() % (max - min + 1) + min;
}
#endif

#ifdef TEST
std::vector<std::vector<int>>
TestQuickSort(int sample_count) {
    std::vector<std::vector<int>> result;
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < sample_count; i++) {
        // Generate a sample
        std::vector<int> sample(GetRandomNum(0, 100));
        for (decltype(sample.size()) i = 0; i < sample.size(); i++) {
            sample[i] = GetRandomNum(0, 30);
        }
        printf("---------------------\n");
        printf("sample:");
        for (auto x : sample) {
            printf(" %d", x);
        }
        printf("\n");

        // This array will be used to be sorted by function "InsertionSort()"
        int* tested_array = new int[sample.size()];
        for (decltype(sample.size()) i = 0; i < sample.size(); i++) {
            tested_array[i] = sample[i];
        }

        // This array will be sorted by function "std::sort()"
        std::vector<int> answer = sample;

        QuickSort(tested_array, 0, sample.size());
        std::sort(answer.begin(), answer.end());
        bool no_error = true;
        for (decltype(sample.size()) i = 0; i < sample.size(); i++) {
            if (tested_array[i] != answer[i]) {
                no_error = false;
                break;
            }
        }
        if (!no_error) {
            result.push_back(sample);
        }
        // printf("Result: %s\n", no_error ? "correct" : "error");
    }
    return result;
}
#endif

#ifdef PRINT
int
main(void) {
#ifdef TEST
    std::vector<std::vector<int>> r = TestQuickSort(5);
    printf("result:\n");
    for (auto v : r) {
        for (auto i : v) {
            printf("%d ", i);
        }
        printf("\n");
    }
#endif
    return 0;
}
#endif
