/*
Title: 3Sum

Description:
Given an array nums of n integers,
are there elements a, b, c in nums such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (decltype(nums.size()) i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int stable = nums[i];
            int low = i + 1;
            int high = nums.size() - 1;
            int sum = 0 - stable;
            while (low < high) {
                if (sum == nums[low] + nums[high]) {
                    vector<int> buffer;
                    buffer.push_back(nums[i]);
                    buffer.push_back(nums[low]);
                    buffer.push_back(nums[high]);
                    result.push_back(buffer);
                    while (low < high && nums[low] == nums[low + 1]) {
                        ++low;
                    }
                    while (low < high && nums[high] == nums[high - 1]) {
                        --high;
                    }
                    ++low;
                    --high;
                } else if (sum < nums[low] + nums[high]) {
                    --high;
                } else {
                    ++low;
                }
            }
        }
        return result;
    }
};