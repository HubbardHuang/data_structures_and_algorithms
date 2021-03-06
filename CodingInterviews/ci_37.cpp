/*
题目：数字在排序数组中出现的次数

题目描述：
统计一个数字在排序数组中出现的次数。
*/

class Solution {
private:
    // 法一，递归版
    int BinarySearch(const vector<int>& data, double target, int start, int end) {
        if (start > end) {
            return start;
        }
        int mid = (end - start) / 2 + start;
        if (data[mid] < target) {
            return BinarySearch(data, target, mid + 1, end);
        } else {
            return BinarySearch(data, target, start, mid - 1);
        }
    }
    // 法一，迭代版
    int BinarySearch(const vector<int>& data, double target) {
        int start = 0;
        int end = data.size() - 1;
        while (start <= end) {
            int mid = (end + start) / 2;
            if (data[mid] < target) {
                start = mid + 1;
            } else if (data[mid] > target) {
                end = mid - 1;
            }
        }
        return start;
    }
    // 法二，递归版
    int FindFirstIndex(const vector<int>& data, int target, int start, int end) {
        if (start > end) {
            return -1;
        }
        int mid = (end + start) / 2;
        if (data[mid] > target) {
            return FindFirstIndex(data, target, start, mid - 1);
        } else if (data[mid] < target) {
            return FindFirstIndex(data, target, mid + 1, end);
        } else if (mid >= 1 && data[mid - 1] == target) {
            return FindFirstIndex(data, target, start, mid - 1);
        } else {
            return mid;
        }
    }
    int FindLastIndex(const vector<int>& data, int target, int start, int end) {
        if (start > end) {
            return -1;
        }
        int mid = (end + start) / 2;
        if (data[mid] > target) {
            return FindLastIndex(data, target, start, mid - 1);
        } else if (data[mid] < target) {
            return FindLastIndex(data, target, mid + 1, end);
        } else if (mid >= 0 && mid + 1 <= data.size() - 1 && data[mid + 1] == target) {
            return FindLastIndex(data, target, mid + 1, end);
        } else {
            return mid;
        }
    }
    // 法二，迭代版
    int FindFirstIndex(const vector<int>& data, int target) {
        int start = 0;
        int end = data.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (data[mid] < target) {
                start = mid + 1;
            } else if (target < data[mid]) {
                end = mid - 1;
            } else if (mid - 1 >= 0 && data[mid - 1] == target) {
                end = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
    int FindLastIndex(const vector<int>& data, int target) {
        int start = 0;
        int end = data.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (data[mid] < target) {
                start = mid + 1;
            } else if (target < data[mid]) {
                end = mid - 1;
            } else if (mid + 1 < data.size() && data[mid + 1] == target) {
                start = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

public:
    int GetNumberOfK(vector<int> data, int k) {
        if (data.empty()) {
            return 0;
        }
        // // 法一，递归版
        // return BinarySearch(data, k + 0.5, 0, data.size() - 1) -
        //        BinarySearch(data, k - 0.5, 0, data.size() - 1);

        // // 法一，迭代版
        // return BinarySearch(data, k + 0.5) - BinarySearch(data, k - 0.5);

        // // 法二，递归版
        // int first_index = FindFirstIndex(data, k, 0, data.size() - 1);
        // int last_index = FindLastIndex(data, k, 0, data.size() - 1);
        // if (first_index != -1 && last_index != -1) {
        //     return last_index - first_index + 1;
        // } else {
        //     return 0;
        // }

        // 法二，迭代版
        int first_index = FindFirstIndex(data, k);
        int last_index = FindLastIndex(data, k);
        if (first_index != -1 && last_index != -1) {
            return last_index - first_index + 1;
        } else {
            return 0;
        }
    }
};