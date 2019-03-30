#include "insertion_sort.h"
#include <algorithm>
#include <cstdio>

void
Print(int nums[], int start_index, int end_index) {
    for (int i = start_index; i < end_index; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
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

int
main(void) {
    int nums[] = { 7, 20, 19, 1, 19, 15, 12, 16, 13, 1, 8, 11, 19, 15, 10, 4, 18, 9, 1 };
    int arr[] = { 7, 20, 19, 1, 19, 15, 12, 16, 13, 1, 8, 11, 19, 15, 10, 4, 18, 9, 1 };
    Print(nums, 0, 19);
    InsertionSort(nums, 0, 19);
    std::sort(arr, arr + 19);
    Print(nums, 0, 19);
    Print(arr, 0, 19);
    return 0;
}
