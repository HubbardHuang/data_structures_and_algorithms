/*
Title: Valid Palindrome

Description:
Given a string, determine if it is a palindrome,
considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem,
we define empty string as valid palindrome.

Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:
Input: "race a car"
Output: false
*/

class Solution {
private:
    inline bool IsValidCharacter(char c) { return isalnum(c); }

public:
    bool isPalindrome(string& s) {
        // Method 1
        int length = s.size();
        int left = 0;
        int right = length - 1;
        while (true) {
            while (left <= right && !IsValidCharacter(s[left])) {
                left++;
            }
            while (left <= right && !IsValidCharacter(s[right])) {
                right--;
            }
            if (left > right) {
                break;
            }
            if (left <= right && toupper(s[left]) != toupper(s[right])) {
                return false;
            } else {
                left++;
                right--;
            }
        }
        return true;

        /*
        // method 2
        if (s.empty()) {
            return true;
        }
        for (int left = 0, right = s.size() - 1; left <= right;) {
            if (isalpha(s[left]) && isalpha(s[right])) {
                if ((s[left] | (1 << 5)) != (s[right] | (1 << 5))) {
                    return false;
                }
                left++;
                right--;
            } else if (isdigit(s[left]) && isdigit(s[right])) {
                if (s[left] != s[right]) {
                    return false;
                }
                left++;
                right--;
            } else {
                if (isdigit(s[left]) && isalpha(s[right])) {
                    return false;
                }
                if (isdigit(s[right]) && isalpha(s[left])) {
                    return false;
                }
                if (!isalpha(s[left]) && !isdigit(s[left])) {
                    left++;
                }
                if (!isalpha(s[right]) && !isdigit(s[right])) {
                    right--;
                }
            }
        }
        return true;
        */
    }
};