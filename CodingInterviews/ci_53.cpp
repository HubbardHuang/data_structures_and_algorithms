/*
题目：表示数值的字符串

题目描述：
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100"，"5e2","-123"，"3.1416"和"-1E-16"都表示数值。
但是"12e"，"1a3.14"，"1.2.3"，"+-5"和"12e+4.3"都不是。
*/

class Solution {
public:
    bool isNumeric(char* string) {
        int length = strlen(string);
        if (!length) {
            return false;
        }
        if (length == 1 && !isdigit(string[0])) {
            return false;
        }

        char* exp_ptr = strchr(string, 'E');
        if (!exp_ptr) {
            exp_ptr = strchr(string, 'e');
        }
        char* dec_ptr = strchr(string, '.');

        if (exp_ptr) { // 若为幂数
            if (*(exp_ptr + 1) == '\0') {
                return false;
            }
            int point_count = 0;
            for (char* it = string; it != exp_ptr; it++) {
                if (it == string && !(*it == '+' || *it == '-' || isdigit(*it))) {
                    return false;
                } else if (it != string && *it == '.') {
                    ++point_count;
                    if (point_count > 1) {
                        return false;
                    }
                } else if (it != string && !isdigit(*it)) {
                    return false;
                }
            }
            for (char* it = exp_ptr + 1; *it != '\0'; it++) {
                if (it == exp_ptr + 1 && !(*it == '+' || *it == '-' || isdigit(*it))) {
                    return false;
                } else if (it != exp_ptr + 1 && !isdigit(*it)) {
                    return false;
                }
            }
            return true;
        }

        if (dec_ptr) { // 若为小数
            if (*(dec_ptr + 1) == '\0') {
                return false;
            }
            for (char* it = string; it != dec_ptr; it++) {
                if (it == string && !(*it == '+' || *it == '-' || isdigit(*it))) {
                    return false;
                } else if (it != string && !isdigit(*it)) {
                    return false;
                }
            }
            for (char* it = dec_ptr + 1; *it != '\0'; it++) {
                if (!isdigit(*it)) {
                    return false;
                }
            }
            return true;
        }

        // 若为普通整数
        for (char* it = string; *it != '\0'; it++) {
            if (it == string && !(*it == '+' || *it == '-' || isdigit(*it))) {
                return false;
            } else if (it != string && !isdigit(*it)) {
                return false;
            }
        }
        return true;
    }
};