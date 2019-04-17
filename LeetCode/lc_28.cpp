/*
Title: Implement strStr()

Description:
Implement strStr().
Return the index of the first occurrence of needle in haystack,
or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:
What should we return when needle is an empty string?
This is a great question to ask during an interview.
For the purpose of this problem,
we will return 0 when needle is an empty string.
This is consistent to C's strstr() and Java's indexOf().
*/

class Solution {
private:
    vector<int> GetNext(string s) {
        std::vector<int> next(s.size(), 0);
        if (next.size() == 0) {
            return next;
        }
        // s.size() >= 1
        next[0] = 0;
        int j = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[j]) {
                next[i] = next[i - 1] + 1;
                ++j;
            } else {
                next[i] = 0;
                j = 0;
                if (s[i] == s[i - 1] && next[i - 1]) {
                    next[i] = next[i - 1];
                    j++;
                }
            }
        }
        for (int i = s.size() - 1; i >= 1; i--) {
            next[i] = next[i - 1];
        }
        next[0] = -1;
        return next;
    }

public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        if (haystack.size() < needle.size()) {
            return -1;
        }
        bool match = false;
        vector<int> next = GetNext(needle);
        int j, k = 0;
        // k: 从 needle 的第 k 位开始匹配
        // j: haystack 正在尝试匹配的第 j 位
        for (int i = 0; i < haystack.size();) {
            if (haystack.size() - i < needle.size()) {
                break;
            }
            for (k = (k == 0 ? 0 : next[k]), j = i + k; k < needle.size(); j++, k++) {
                if (haystack[j] != needle[k]) {
                    match = false;
                    break;
                } else if (k == needle.size() - 1) {
                    match = true;
                    break;
                }
            }
            if (match) {
                return i;
            } else {
                i = i + k - next[k];
            }
        }
        return -1;
    }
};