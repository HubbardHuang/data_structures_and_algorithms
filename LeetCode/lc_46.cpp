/*
Title: Permutations

Description:
Given a collection of distinct integers,
return all possible permutations.

Example:
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
private:
    void Recursion(vector<int>& nums, int begin, vector<vector<int>>& result) {
        if (begin == nums.size() - 1) {
            result.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); i++) {
            if (nums[i] == nums[begin] && i != begin) {
                continue;
            }
            swap(nums[i], nums[begin]);
            Recursion(nums, begin + 1, result);
            swap(nums[i], nums[begin]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) {
            return result;
        }
        Recursion(nums, 0, result);
        return result;
    }
};