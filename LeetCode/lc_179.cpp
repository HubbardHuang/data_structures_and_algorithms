/*
Title: Largest Number

Description:
Given a list of non negative integers,
arrange them such that they form the largest number.

Example 1:
Input: [10,2]
Output: "210"

Example 2:
Input: [3,30,34,5,9]
Output: "9534330"

Note:
The result may be very large,
so you need to return a string instead of an integer.
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        bool all_is_zero = true;
        for (auto i : nums) {
            if (i != 0) {
                all_is_zero = false;
                break;
            }
        }
        if (all_is_zero) {
            return "0";
        }

        string result = "";
        vector<string> strs;
        for (auto i : nums) {
            strs.push_back(to_string(i));
        }
        auto str_cmp = [](const string& left, const string& right) {
            string lr = left + right;
            string rl = right + left;
            int length = left.size() + right.size();
            for (int i = 0; i < length; i++) {
                if (lr[i] < rl[i]) {
                    return false;
                } else if (lr[i] > rl[i]) {
                    return true;
                }
            }
            return true;
        };
        sort(strs.begin(), strs.end(), str_cmp);
        for (auto str : strs) {
            result += str;
        }
        return result;
    }
};