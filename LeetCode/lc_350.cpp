/*
Title: Intersection of Two Arrays II

Description:
Given two arrays, write a function to compute their intersection.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

Follow up:
What if the given array is already sorted?
How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size?
Which algorithm is better?
What if elements of nums2 are stored on disk,
and the memory is limited such that
you cannot load all elements into the memory at once?
*/

class Solution {
public:
    vector<int> intersect(vector<int>& left_nums, vector<int>& right_nums) {
        vector<int> intersection;
        int left_length = left_nums.size();
        int right_length = right_nums.size();
        if (!left_length || !right_length) {
            return intersection;
        }

        // // method 1
        // unordered_map<int, int> count;
        // for (auto n : left_nums) {
        //     count[n]++;
        // }
        // for (auto n : right_nums) {
        //     if (count[n] > 0) {
        //         --count[n];
        //         intersection.push_back(n);
        //     }
        // }

        // method 2
        sort(left_nums.begin(), left_nums.end());
        sort(right_nums.begin(), right_nums.end());
        auto left_it = left_nums.begin();
        auto right_it = right_nums.begin();
        while (left_it != left_nums.end() && right_it != right_nums.end()) {
            if (*left_it < *right_it) {
                ++left_it;
            } else if (*right_it < *left_it) {
                ++right_it;
            } else {
                intersection.push_back(*left_it);
                ++left_it;
                ++right_it;
            }
        }

        return intersection;
    }
};