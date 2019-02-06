/*
题目：连续子数组的最大和

题目描述：
例如{6, -3, -2, 7, -15, 1, 2, 2}，连续子向量的最大和为8(从第0个开始，到第3个为止。
给一个数组，返回它的最大连续子序列的和。
*/
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int length = array.size();
        if (length == 1) {
            return array[0];
        }
        int result = array[0];
        int max = array[0];
        for (int i = 1; i < length; i++) {
            max = (max + array[i] > array[i]) ? (max + array[i]) : array[i];
            result = (result > max) ? result : max;
        }
        return result;
    }
};