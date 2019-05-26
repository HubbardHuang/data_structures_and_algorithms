/*
Title: Search in Rotated Sorted Array

Description:
Suppose an array sorted in ascending order
is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search.
If found in the array return its index,
otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

class Solution {
private:
    int FindMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

public:
    int search(vector<int>& nums, int target) {
        int pivot_index = FindMin(nums);
        int low = 0;
        int high = nums.size();
        while (low < high) {
            int fake_mid = low + (high - low) / 2;
            int real_mid = (fake_mid + pivot_index) % nums.size();
            if (nums[real_mid] < target) {
                low = fake_mid + 1;
            } else if (nums[real_mid] > target) {
                high = fake_mid;
            } else {
                return real_mid;
            }
        }
        return -1;
    }
};