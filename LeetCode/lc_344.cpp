/*
Title: Reverse String

Description:
Write a function that reverses a string.
The input string is given as an array of characters char[].
Do not allocate extra space for another array,
you must do this by modifying the input array in-place with O(1) extra memory.
You may assume all the characters consist of printable ascii characters.

Example 1:
Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int length = s.size();
        if (length == 0) {
            return;
        }
        int left_index = 0;
        int right_index = length - 1;
        while (left_index <= right_index) {
            char temp = s[left_index];
            s[left_index] = s[right_index];
            s[right_index] = temp;
            left_index++;
            right_index--;
        }
    }
};