/*
Title: Missing Number

Description:
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
find the one that is missing from the array.

Example 1:
Input: [3,0,1]
Output: 2

Example 2:
Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Note:
Your algorithm should run in linear runtime complexity.
Could you implement it using only constant extra space complexity?
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
        int n = nums.size();
        int curr_sum = 0;
        for (int i = 0; i < n; i++) {
            curr_sum += nums[i];
        }
        int sum = (1 + n) * n / 2;
        return sum - curr_sum;
        */
        int length = nums.size();
        int answer = 0;
        int i;
        for (i = 0; i < length; i++) {
            answer = answer ^ i ^ nums[i];
        }
        return answer ^ i;
    }
};