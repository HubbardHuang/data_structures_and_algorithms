/*
Title: Subsets

Description:
Given a set of distinct integers, nums,
return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
private:
    vector<vector<int>> result;
    void Backtrack(const vector<int>& nums, vector<int>& buffer, int start) {
        result.push_back(buffer);
        for (int i = start; i < nums.size(); i++) {
            buffer.push_back(nums[i]);
            Backtrack(nums, buffer, i + 1);
            buffer.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        /* Method 1 */
        // vector<int> buffer;
        // Backtrack(nums, buffer, 0);
        // return result;

        /* Method 2 */
        int length = nums.size();
        int subset_total = 1 << length;
        vector<vector<int>> subset(subset_total);
        for (int i = 0; i < subset_total; i++) {
            for (int k = 0; k < length; k++) {
                if ((i >> k) & 1) {
                    subset[i].push_back(nums[k]);
                }
            }
        }
        return subset;
    }
};