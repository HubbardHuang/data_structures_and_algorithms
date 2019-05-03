/*
Title: Generate Parentheses

Description:
Given n pairs of parentheses,
write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
private:
    vector<string> result;
    void Recursion(string& str, int n, int m) {
        if (n == 0 && m == 0) {
            result.push_back(str);
            return;
        }
        if (m > 0) {
            str += ')';
            Recursion(str, n, m - 1);
            str.pop_back();
        }
        if (n > 0) {
            str += '(';
            Recursion(str, n - 1, m + 1);
            str.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string str = "";
        Recursion(str, n, 0);
        return result;
    }
};