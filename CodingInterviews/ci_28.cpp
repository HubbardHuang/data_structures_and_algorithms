/*
题目：数组中出现次数超过一半的数字

题目描述：
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int length = numbers.size();
        if (length == 0) {
            return 0;
        }
        int result = numbers[0];
        int count = 1;
        for (int i = 1; i < length; i++) {
            if (numbers[i] == result) {
                ++count;
            } else {
                --count;
                if (count == 0) {
                    result = numbers[i];
                    count = 1;
                }
            }
        }
        int same = 0;
        for (int i = 0; i < length; i++) {
            if (numbers[i] == result) {
                ++same;
            }
        }
        if (same > length / 2) {
            return result;
        } else {
            return 0;
        }
    }
};