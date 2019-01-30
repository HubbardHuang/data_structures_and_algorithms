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
        // return PowerOfTwo(number - 1);

        // 法二
        return 1 << (number - 1);
    }

private:
    // 二分法求某个数（这里为2）的x次方
    int PowerOfTwo(int x) {
        if (x == 0) {
            return 1;
        }
        if (x & 1 == 1) {
            return 2 * PowerOfTwo(x / 2) * PowerOfTwo(x / 2);
        } else {
            return PowerOfTwo(x / 2) * PowerOfTwo(x / 2);
        }
    }
};