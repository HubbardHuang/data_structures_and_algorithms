/*
Title: Binary Search

Description:
Given a sorted (in ascending order) integer array nums
of n elements and a target value,
write a function to search target in nums.
If target exists, then return its index, otherwise return -1.

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

Note:
    You may assume that all elements in nums are unique.
    n will be in the range [1, 10000].
    The value of each element in nums will be in the range [-9999, 9999].
*/

class Solution {
private:
    int SearchIteratively(const vector<int> nums, int left_index, int right_index,
                          int target) {
        while (left_index < right_index) {
            int mid_index = left_index + (right_index - left_index) / 2;
            if (nums[mid_index] > target) {
                right_index = mid_index;
            } else if (nums[mid_index] < target) {
                left_index = mid_index + 1;
            } else {
                return mid_index;
            }
        }
        return -1;
    }
    int SearchRecursively(const vector<int>& nums, int left_index, int right_index,
                          int target) {
        if (left_index == right_index) {
            return -1;
        }
        int mid_index = left_index + (right_index - left_index) / 2;
        if (nums[mid_index] < target) {
            return SearchRecursively(nums, mid_index + 1, right_index, target);
        } else if (target < nums[mid_index]) {
            return SearchRecursively(nums, left_index, mid_index, target);
        } else {
            return mid_index;
        }
    }

public:
    int search(vector<int>& nums, int target) {
        // return SearchIteratively(nums, 0, nums.size(), target);
        return SearchRecursively(nums, 0, nums.size(), target);
    }
};