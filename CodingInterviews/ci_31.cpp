/*
题目：从1到n整数中1出现的次数
*/

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int count = 0;
        for (int i = 1; i <= n; i *= 10) {
            int a = n / i, b = n % i;
            count += (a + 8) / 10 * i + ((a % 10 == 1) ? (b + 1) : 0);
        }
        return count;
    }
};