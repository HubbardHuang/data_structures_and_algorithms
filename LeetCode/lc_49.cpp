/*
Title: Group Anagrams

Description:
Given an array of strings,
group anagrams together.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
    All inputs will be in lowercase.
    The order of your output does not matter.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        using LL = unsigned long long;
        vector<LL> prime = { 2,  3,  5,  7,  11, 13, 17,  19, 23,
                             29, 31, 41, 43, 47, 53, 59,  61, 67,
                             71, 73, 79, 83, 89, 97, 101, 103 };
        vector<vector<string>> result;
        map<LL, int> key_to_index;
        for (auto str : strs) {
            LL key = 1;
            auto temp_str = str;
            sort(temp_str.begin(), temp_str.end());
            for (auto c : temp_str) {
                key *= prime[c - 'a'];
            }
            vector<string> vs;
            auto p = key_to_index.find(key);
            if (p != key_to_index.end()) {
                result[p->second].push_back(str);
            } else {
                result.push_back(vs);
                key_to_index.insert({ key, result.size() - 1 });
                result.back().push_back(str);
            }
        }
        return result;
    }
};