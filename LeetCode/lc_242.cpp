/*
Title: Valid Anagram

Description:
Given two strings s and t,
write a function to determine if t is an anagram of s.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters?
How would you adapt your solution to such case?
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = { 0 };
        for (auto c : s)
            record[c - 'a']++;
        for (auto c : t)
            record[c - 'a']--;
        for (auto i : record)
            if (i)
                return false;
        return true;
    }
};