/*
题目：变态跳台阶

题目描述：
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

class Solution {
public:
    int jumpFloorII(int number) {
        // 法一
        return Power(2, number - 1);

        // 法二
        // return 1 << (number - 1);
    }

private:
    // 分治法求整数数的x次方，x为非负整数
    int Power(int n, int x) {
        if (x == 0) {
            return 1;
        }
        if (x & 1 == 1) {
            return n * Power(n * n, x / 2);
        } else {
            return Power(n * n, x / 2);
        }
    }
};