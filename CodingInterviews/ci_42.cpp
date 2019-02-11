/*
题目：和为S的两个数字

题目描述：
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S。
如果有多对数字的和等于S，输出两个数的乘积最小的。
*/

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        auto low = array.begin();
        auto high = array.rbegin();
        vector<int> result;
        while (low != array.end() && high != array.rend() && *low <= *high) {
            int curr = (*low) + (*high);
            if (curr == sum) {
                result.push_back(*low);
                result.push_back(*high);
                break;
            } else if (curr > sum) {
                ++high;
            } else {
                ++low;
            }
        }
        return result;
    }
};