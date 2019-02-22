/*
Title: Sum of Two Integers

Description:
Calculate the sum of two integers a and b,
but you are not allowed to use the operator + and -.

Example 1:
Input: a = 1, b = 2
Output: 3

Example 2:
Input: a = -2, b = 3
Output: 1
*/

class Solution {
public:
    int getSum(int left, int right) {
        // // method 1
        // int answer = 0;
        // int carry = 0;
        // for (int i = 0; i < 32; i++) {
        //     int left_bit = left & 1;
        //     int right_bit = right & 1;
        //     // xor
        //     answer |= (left_bit ^ right_bit ^ carry) << i;
        //     // change the carry
        //     if (carry == 1) {
        //         carry &= left_bit | right_bit;
        //     } else {
        //         carry |= left_bit & right_bit;
        //     }
        //     // iteration
        //     left >>= 1;
        //     right >>= 1;
        // }
        // return answer;

        // method 2
        int carry = 0;
        int sum = left;
        while (right != 0) {
            carry = left & right;
            sum = left ^ right;
            right = ((carry & 0xffffffff) << 1);
            left = sum;
        }
        return sum;
    }
};