/*
题目：左旋转字符串

题目描述：
汇编语言中有一种移位指令叫做循环左移（ROL），
现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S =“abcXYZdef”，要求输出循环左移3位后的结果，即“XYZdefabc”。
*/

class Solution {
public:
    enum class Direction { Left, Right };
    string LeftRotateString(string& str, int n) {
        return Rotate(str, Direction::Left, n);
    }

private:
    string Rotate(string& str, Direction direction, int step) {
        int length = str.size();
        if (length == 0) {
            return str;
        }
        step %= length;

        int partition = 0;
        if (direction == Direction::Left) {
            partition = length - step;
        } else if (direction == Direction::Right) {
            partition = step;
        }
        reverse(str.begin(), str.end());
        reverse(str.begin() + partition, str.end());
        reverse(str.begin(), str.begin() + partition);
        return str;
    }
};