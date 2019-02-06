/*
题目：最小的K个数

题目描述：
输入n个整数，找出其中最小的K个数。
例如输入4, 5, 1, 6, 2, 7, 3, 8这8个数字，
则最小的4个数字是1, 2, 3, 4,
*/

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int length = input.size();
        vector<int> result;
        if (k == 0 || k > length || length == 0) {
            result.clear();
            return result;
        }
        priority_queue<int, vector<int>> min_k;
        for (int i = 0; i < k; i++) {
            min_k.push(input[i]);
        }
        for (int i = k; i < length; i++) {
            if (min_k.top() > input[i]) {
                min_k.pop();
                min_k.push(input[i]);
            }
        }
        while (!min_k.empty()) {
            result.push_back(min_k.top());
            min_k.pop();
        }
        return result;
    }
};