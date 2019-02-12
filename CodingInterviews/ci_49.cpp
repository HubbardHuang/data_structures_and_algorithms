/*
题目：把字符串转换成整数

题目描述：
将一个字符串转换成一个整数的功能，但是string不符合数字要求时返回0）。
要求不能使用字符串转换整数的库函数。
数值为0或者字符串不是一个合法的数值则返回0。
*/

class Solution {
public:
    int StrToInt(string str) {
        int length = str.size();
        if (length == 0) {
            return 0;
        }
        for (auto i = str.begin(); i != str.end(); i++) {
            if (i == str.begin()) {
                if (!(*i == '+' || *i == '-' || ('0' <= *i && *i <= '9')))
                    return 0;
            } else if (*i < '0' || *i > '9') {
                return 0;
            }
        }
        int result = 0;
        for (int i = length - 1; i >= 0; i--) {
            if (str[i] == '-') {
                result = 0 - result;
            } else if (str[i] == '+') {
                result = result;
            } else {
                result += (str[i] - '0') * pow(10, length - i - 1);
            }
        }
        return result;
    }
};