#include <algorithm>
#include <cstdio>
#include <ctime>
#include <vector>

#include "insertion_sort.h"

#ifdef RELEASE
void
InsertionSort(int nums[], size_t start_index, size_t end_index) {
    if (start_index >= end_index) {
        return;
    }

    for (size_t i = start_index + 1; i < end_index; i++) {
        int inserted = nums[i];
        size_t seat = i;
        for (size_t k = i - 1; start_index <= k && k < end_index && inserted < nums[k];
             k--) {
            nums[k + 1] = nums[k];
            seat = k; // update the seat where will be inserted the variable "inserted"
        }
        nums[seat] = inserted;
    }
}
#endif

#ifdef PRINT
void
Print(int nums[], int start_index, int end_index) {
    for (int i = start_index; i < end_index; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
#endif

#ifdef PRINT
void
InsertionSort(int nums[], size_t start_index, size_t end_index) {
    if (start_index >= end_index) {
        return;
    }

    for (size_t i = start_index + 1; i < end_index; i++) {
        int inserted = nums[i];
        size_t seat = i;
#ifdef DEBUG
        printf("inserted = %d\n", inserted);
#endif
        for (size_t k = i - 1; start_index <= k && k < end_index && inserted < nums[k];
             k--) {
            nums[k + 1] = nums[k];
            seat = k;
#ifdef DEBUG
            printf("in for-for-if: ");
            Print(nums, start_index, end_index);
#endif
        }
        nums[seat] = inserted;
#ifdef DEBUG
        printf("in for: ");
        printf("seat=%d,", seat);
        Print(nums, start_index, end_index);
#endif
    }
}
#endif

#ifdef TEST
size_t
GetRandomNum(size_t min, size_t max) {
    return rand() % (max - min + 1) + min;
}
#endif

#ifdef TEST
void
TestInsertionSort(int sample_count) {
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < sample_count; i++) {
        // Generate a sample
        std::vector<int> sample(GetRandomNum(0, 20));
        for (decltype(sample.size()) i = 0; i < sample.size(); i++) {
            sample[i] = GetRandomNum(0, 15);
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

        InsertionSort(tested_array, 0, sample.size());
        std::sort(answer.begin(), answer.end());
        bool no_error = true;
        for (decltype(sample.size()) i = 0; i < sample.size(); i++) {
            if (tested_array[i] != answer[i]) {
                no_error = false;
                break;
            }
        }
        printf("Result: %s\n", no_error ? "correct" : "error");
    }
}
#endif

#ifdef PRINT
int
main(void) {
#ifdef TEST
    TestInsertionSort(10);
#endif
    return 0;
}
#endif
