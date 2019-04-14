/*
Title: Longest Common Prefix

Description:
Write a function to find the longest common prefix string
amongst an array of strings.
If there is no common prefix,
return an empty string "".

Example 1:
Input: ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Note:
All given inputs are in lowercase letters a-z.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        if (strs.size() == 1) {
            return strs[0];
        }
        int prefix_length = strs[0].size();
        for (int i = 1; i < strs.size() && prefix_length > 0; i++) {
            string s = strs[i];
            int k = 0;
            for (; k < s.size() && k < prefix_length; k++) {
                if (strs[0][k] != s[k]) {
                    break;
                }
            }
            prefix_length = k;
        }
        return strs[0].substr(0, prefix_length);
    }
};