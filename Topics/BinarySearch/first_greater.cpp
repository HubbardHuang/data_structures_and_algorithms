#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 升序有重复数，查找第一个大于 target 的 A[i]，迭代版
 */
int
SearchFirstGreaterIteratively(const vector<int>& array, int left_index, int right_index,
                              int target) {
    while (left_index < right_index) {
        int mid_index = left_index + (right_index - left_index) / 2;
        if (target < array[mid_index]) {
            right_index = mid_index;
        } else if (array[mid_index] < target) {
            left_index = mid_index + 1;
        } else { // 关键点一
            left_index = mid_index + 1;
        }
    }
    // 关键点二
    if (left_index < array.size() && array[left_index] > target) {
        return left_index;
    } else {
        return -1;
    }
}

/**
 * 升序有重复数，查找第一个大于 target 的 A[i]，递归版
 */
int
SearchFirstGreaterRecursively(const vector<int>& array, int left_index, int right_index,
                              int target) {
    if (left_index == right_index) {
        // 关键点二
        if (left_index < array.size() && array[left_index] > target) {
            return left_index;
        } else {
            return -1;
        }
    }
    int mid_index = left_index + (right_index - left_index) / 2;
    if (array[mid_index] < target) {
        return SearchFirstGreaterRecursively(array, mid_index + 1, right_index, target);
    } else if (target < array[mid_index]) {
        return SearchFirstGreaterRecursively(array, left_index, mid_index, target);
    } else { // 关键点一
        return SearchFirstGreaterRecursively(array, mid_index + 1, right_index, target);
    }
}

int
main(void) {
    vector<int> arr = { 1, 2, 2, 3, 6, 6, 6, 8, 12, 14 };
    int index = 0;
    int target = 0;

    cout << "array:";
    for (auto i : arr) {
        cout << ' ' << i;
    }
    cout << endl;

    cout << "---------------\nTest Iteration:" << endl;

    index = SearchFirstGreaterIteratively(arr, 0, arr.size(), target = 10);
    cout << "target = " << target << ": index = " << index << endl;

    index = SearchFirstGreaterIteratively(arr, 0, arr.size(), target = 1);
    cout << "target = " << target << ": index = " << index << endl;

    index = SearchFirstGreaterIteratively(arr, 0, arr.size(), target = 2);
    cout << "target = " << target << ": index = " << index << endl;

    index = SearchFirstGreaterIteratively(arr, 0, arr.size(), target = 6);
    cout << "target = " << target << ": index = " << index << endl;

    index = SearchFirstGreaterIteratively(arr, 0, arr.size(), target = 14);
    cout << "target = " << target << ": index = " << index << endl;

    index = SearchFirstGreaterIteratively(arr, 0, arr.size(), target = 100);
    cout << "target = " << target << ": index = " << index << endl;

    cout << "---------------\nTest Recursion:" << endl;

    index = SearchFirstGreaterRecursively(arr, 0, arr.size(), target = 10);
    cout << "target = " << target << ": index = " << index << endl;

    index = SearchFirstGreaterRecursively(arr, 0, arr.size(), target = 1);
    cout << "target = " << target << ": index = " << index << endl;

    index = SearchFirstGreaterRecursively(arr, 0, arr.size(), target = 2);
    cout << "target = " << target << ": index = " << index << endl;

    index = SearchFirstGreaterRecursively(arr, 0, arr.size(), target = 6);
    cout << "target = " << target << ": index = " << index << endl;

    index = SearchFirstGreaterRecursively(arr, 0, arr.size(), target = 14);
    cout << "target = " << target << ": index = " << index << endl;

    index = SearchFirstGreaterRecursively(arr, 0, arr.size(), target = 100);
    cout << "target = " << target << ": index = " << index << endl;

    return 0;
}