/*
题目：数值的整数次方

题目描述：
给定一个double类型的浮点数base和int类型的整数exponent。
求base的exponent次方。
*/

class Solution {
public:
    double Power(double base, int exponent) {
        /*
        // 二分法递归版
        if (exponent == 0) {
            return 1;
        }
        if (exponent < 0) {
            return 1 / Power(base, -exponent);
        }
        if (exponent & 1) {
            return base * Power(base * base, exponent / 2);
        } else {
            return Power(base * base, exponent / 2);
        }
        */

        // 二分法迭代版
        int exp = abs(exponent);
        double result = 1;
        while (exp) {
            if (exp & 1 == 1) {
                result *= base;
            }
            base = base * base;
            result *= base;
            exp /= 2;
            if (exp == 1) {
                break;
            }
        }
        return exponent > 0 ? result : 1 / result;
    }
};