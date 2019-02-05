/*
题目：字符串的排列

题目描述：
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
*/

class Solution {
private:
    void Recursive(string str, int begin, vector<string>& result) {
        if (begin == str.size() - 1) {
            result.push_back(str);
        }
        for (int i = begin; i < str.size(); i++) {
            if (i != begin && str[i] == str[begin]) {
                continue;
            }
            swap(str[i], str[begin]);
            Recursive(str, begin + 1, result);
            swap(str[i], str[begin]);
        }
    }

public:
    vector<string> Permutation(string str) {
        vector<string> result;
        result.clear();
        if (str.empty()) {
            return result;
        }
        Recursive(str, 0, result);
        sort(result.begin(), result.end());
        return result;
    }
};