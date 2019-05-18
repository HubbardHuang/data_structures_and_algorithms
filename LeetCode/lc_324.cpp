/*
Title: Wiggle Sort II

Description:
Given an unsorted array nums,
reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example 1:
Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].

Example 2:
Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int length = nums.size();
        auto midptr = nums.begin() + length / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;

        auto to_original_index = [length](int i) {
            return (1 + i * 2) % (length | 1);
        };
        int i = 0, j = 0, k = length - 1;
        while (j <= k) {
            if (nums[to_original_index(j)] > mid) {
                swap(nums[to_original_index(i)], nums[to_original_index(j)]);
                i++;
                j++;
            } else if (nums[to_original_index(j)] < mid) {
                swap(nums[to_original_index(j)], nums[to_original_index(k)]);
                k--;
            } else {
                j++;
            }
        }
    }
};