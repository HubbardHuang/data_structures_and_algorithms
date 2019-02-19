/*
Title: Reverse Vowels of a String

Description:
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Input: "hello"
Output: "holle"

Example 2:
Input: "leetcode"
Output: "leotcede"

Note:
The vowels does not include the letter "y".
*/

class Solution {
private:
    string vowel = "aeiouAEIOU";
    inline bool IsVowel(char ch) {
        for (int i = 0; i < vowel.size(); i++) {
            if (ch == vowel[i]) {
                return true;
            }
        }
        return false;
    }

public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            while (left < right && !IsVowel(s[left])) {
                ++left;
            }
            while (left < right && !IsVowel(s[right])) {
                --right;
            }
            swap(s[left], s[right]);
            ++left;
            --right;
        }
        return s;
    }
};