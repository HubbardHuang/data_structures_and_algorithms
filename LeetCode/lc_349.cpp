/*
Title: Intersection of Two Arrays

Description:
Given two arrays,
write a function to compute their intersection.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]

Note:
    Each element in the result must be unique.
    The result can be in any order.
*/

class Solution {
private:
    vector<int> FindIntersectionBySet(vector<int>& left, vector<int>& right) {
        // Make sure [left.size()] is greater than [right.size()]
        if (left.size() < right.size()) {
            swap(left, right);
        }

        set<int> set_of_right(right.begin(), right.end());

        vector<int> result;
        for (auto i : left) {
            if (set_of_right.find(i) != set_of_right.end()) {
                result.push_back(i);
                set_of_right.erase(i); // Avoid duplicate matches
            }
        }
        return result;
    }
    vector<int> FindIntersectionBySortAndTwoPointers(vector<int>& left,
                                                     vector<int>& right) {
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        // Make sure [left.size()] is greater than [right.size()]
        if (left.size() < right.size()) {
            swap(left, right);
        }

        vector<int> intersection;
        auto i_long = left.begin();
        auto i_short = right.begin();
        while (i_long != left.end() && i_short != right.end()) {
            if (*i_long < *i_short) {
                i_long++;
            } else if (*i_short < *i_long) {
                i_short++;
            } else {
                if (intersection.empty() || intersection.back() != *i_short) {
                    intersection.push_back(*i_short);
                }
                i_long++;
                i_short++;
            }
        }
        return intersection;
    }

public:
    vector<int> intersection(vector<int>& left, vector<int>& right) {
        // return FindIntersectionBySortAndTwoPointers(left, right);
        return FindIntersectionBySet(left, right);
    }
};