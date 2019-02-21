/*
Title: Move Zeroes

Description:
Given an array nums,
write a function to move all 0's to the end of it
while maintaining the relative order of the non-zero elements.

Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int length = nums.size();
        int non_zero_index = 0;
        for (int i = 0; i < length; i++) {
            if (nums[i] != 0) {
                nums[non_zero_index++] = nums[i];
            }
        }
        fill(nums.begin() + non_zero_index, nums.end(), 0);
    }
};