/*
Title: Plus One

Description:
Given a non-empty array of digits representing a non-negative integer,
plus one to the integer.
The digits are stored such that
the most significant digit is at the head of the list,
and each element in the array contain a single digit.
You may assume the integer does not contain any leading zero,
except the number 0 itself.

Example 1:
Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:
Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        reverse(digits.begin(), digits.end());
        for (int i = 0; i < digits.size() && carry != 0; i++) {
            int next_carry = 0;
            if (digits[i] == 9) {
                next_carry = 1;
                digits[i] = 0;
            } else {
                digits[i]++;
            }
            carry = next_carry;
        }
        if (carry == 1) {
            digits.push_back(1);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};