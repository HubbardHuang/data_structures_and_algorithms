/*
题目：数组中的逆序对

题目描述：
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组，求出这个数组中的逆序对的总数P。
并将P对1000000007取模的结果输出，即输出P%1000000007。
*/

class Solution {
public:
    int InversePairs(vector<int>& data) {
        if (data.empty()) {
            return 0;
        }
        vector<int> copy(data.size());
        long long result = MergeSort(data, copy, 0, data.size() - 1);
        return result % 1000000007;
    }

private:
    long long MergeSort(vector<int>& data, vector<int>& copy, int start, int end) {
        if (start == end) {
            return 0;
        }
        int mid = (start + end) / 2;
        long long left_count = MergeSort(data, copy, start, mid);
        long long right_count = MergeSort(data, copy, mid + 1, end);

        long long count = 0;
        int left_index = mid;
        int right_index = end;
        int copy_index = end;
        while (left_index >= start && right_index >= mid + 1) {
            if (data[left_index] > data[right_index]) {
                copy[copy_index--] = data[left_index--];
                count += (right_index - mid);
            } else {
                copy[copy_index--] = data[right_index--];
            }
        }
        while (left_index >= start) {
            copy[copy_index--] = data[left_index--];
        }
        while (right_index >= mid + 1) {
            copy[copy_index--] = data[right_index--];
        }
        for (int i = start; i <= end; i++) {
            data[i] = copy[i];
        }
        return left_count + right_count + count;
    }
};