/*
题目：和为S的连续正数序列

题目描述：
输出所有和为S的连续正数序列。
序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序。
*/

class Solution {
public:
    vector<vector<int>> FindContinuousSequence(int target) {
        // // 法一
        // int head = 1;
        // int tail = 2;
        // vector<vector<int>> result;
        // while (head < tail) {
        //     int sum = (tail + head) * (tail - head + 1) / 2;
        //     if (sum > target) {
        //         ++head;
        //     } else if (sum < target) {
        //         ++tail;
        //     } else {
        //         vector<int> buffer;
        //         for (int i = head; i <= tail; i++) {
        //             buffer.push_back(i);
        //         }
        //         result.push_back(buffer);
        //         ++head;
        //     }
        // }
        // return result;

        // 法二
        int item_max = (int)sqrt(2 * target);
        vector<vector<int>> result;
        for (int n = item_max; n >= 2; n--) {
            if ((n & 1) == 1 && target % n == 0) {
                vector<int> buffer;
                for (int a = target / n - (n - 1) / 2, k = 0; k < n; a++, k++) {
                    buffer.push_back(a);
                }
                result.push_back(buffer);
            } else if ((n & 1) == 0 && target % (target / n + target / n + 1) == 0) {
                vector<int> buffer;
                for (int a = target / n - (n - 1) / 2, k = 0; k < n; a++, k++) {
                    buffer.push_back(a);
                }
                result.push_back(buffer);
            }
        }
        return result;
    }
};