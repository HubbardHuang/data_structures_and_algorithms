/*
题目：正则表达式匹配

题目描述：
请实现一个函数用来匹配包括'.'和'*'的正则表达式。
模式中的字符'.'表示任意一个字符，
而'*'表示它前面的字符可以出现任意次（包含0次）。
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，
但是与"aa.a"和"ab*a"均不匹配。
*/

class Solution {
public:
    bool match(char* str, char* pattern) {
        int str_size = strlen(str);
        int pattern_size = strlen(pattern);
        if (str_size == 0 && pattern_size == 0) {
            return true;
        }
        if (pattern_size == 0) {
            return false;
        }
        if (pattern[0] == '*') {
            return false;
        }
        enum { YES = 1, NO = 0 };
        vector<vector<int>> match(str_size + 1);
        for (int i = 0; i < match.size(); i++) {
            match[i].resize(pattern_size + 1);
            fill(match[i].begin(), match[i].end(), NO);
        }
        match[0][0] = YES;
        for (int i = 1; i < match[0].size(); i++) {
            if (pattern[i - 1] == '*') {
                match[0][i] = match[0][i - 2];
            }
        }

        for (int i = 1; i < match.size(); i++) {
            for (int k = 1; k < match[0].size(); k++) {
                int s_index = i - 1;
                int p_index = k - 1;
                if (pattern[p_index] == str[s_index] || pattern[p_index] == '.') {
                    match[i][k] = match[i - 1][k - 1];
                } else if (pattern[p_index] == '*') {
                    if (pattern[p_index - 1] != str[s_index] &&
                        pattern[p_index - 1] != '.') {
                        match[i][k] = match[i][k - 2];
                    } else {
                        match[i][k] = match[i - 1][k] | match[i][k - 1] | match[i][k - 2];
                    }
                }
            }
        }
        return match.back().back() == YES;
    }
};