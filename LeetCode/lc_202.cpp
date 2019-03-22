/*
Title: Happy Number

Description:
Write an algorithm to determine if a number is "happy".
A happy number is a number defined by the following process:
Starting with any positive integer,
replace the number by the sum of the squares of its digits,
and repeat the process until the number equals 1 (where it will stay),
or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy numbers.

Example:
Input: 19
Output: true
*/

class Solution {
private:
    int BitSquareSum(int n) {
        int sum = 0;
        while (n) {
            int bit = n % 10;
            sum += bit * bit;
            n /= 10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = BitSquareSum(slow);
            fast = BitSquareSum(fast);
            fast = BitSquareSum(fast);
        } while (slow != fast);
        if (slow == 1) {
            return true;
        } else {
            return false;
        }
    }
};