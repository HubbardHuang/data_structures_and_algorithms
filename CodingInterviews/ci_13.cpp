/*
题目：调整数组顺序使奇数位于偶数前面

题目描述：
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

class Solution {
public:
    void reOrderArray(vector<int>& array) {
        int length = array.size();
        vector<int> temp(length);
        int odd_index = 0;
        int even_index = length - 1;
        int odd_count = 0;
        int even_count = 0;

        for (auto x : array) {
            if (x & 1) {
                temp[odd_index++] = x;
                odd_count++;
            } else {
                temp[even_index--] = x;
                even_count++;
            }
        }

        int i;
        for (i = 0; i < odd_count; i++) {
            array[i] = temp[i];
        }
        int e = length - 1;
        for (; i < length; i++) {
            array[i] = temp[e--];
        }
    }
};