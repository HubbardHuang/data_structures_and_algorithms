/*
Title: Power of Three

Description:
Given an integer, write a function to determine if it is a power of three.

Example 1:
Input: 27
Output: true

Example 2:
Input: 0
Output: false

Example 3:
Input: 9
Output: true

Example 4:
Input: 45
Output: false

Follow up:
Could you do it without using any loop / recursion?
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        const int kMaxPowerOf3 = 1162261467;
        return n > 0 && kMaxPowerOf3 % n == 0;
    }
};