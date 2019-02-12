/*
题目：不用加减乘除做加法

题目描述：
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/

class Solution {
public:
    int Add(int left, int right) {
        int result = 0;
        int carry = 0;
        for (int i = 0; i < 32; i++) {
            int left_bit = left >> i & 1;
            int right_bit = right >> i & 1;
            result |= (left_bit ^ right_bit ^ carry) << i;
            vector<int> count(2, 0);
            count[left_bit]++;
            count[right_bit]++;
            count[carry]++;
            if (count[1] >= 2) {
                carry = 1;
            } else {
                carry = 0;
            }
        }
        return result;
    }
};