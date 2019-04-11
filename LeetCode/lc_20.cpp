/*
Title: Valid Parentheses

Description:
Given a string
containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.
An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true
*/

class Solution {
public:
    bool isValid(string s) {
        map<char, char> match;
        match.insert({ '{', '}' });
        match.insert({ '[', ']' });
        match.insert({ '(', ')' });

        stack<char> buffer_stack;
        for (auto c : s) {
            if (!buffer_stack.empty()) {
                char top_char = buffer_stack.top();
                if (c == match[top_char]) {
                    buffer_stack.pop();
                } else {
                    buffer_stack.push(c);
                }
            } else {
                buffer_stack.push(c);
            }
        }
        return buffer_stack.empty();
    }
};