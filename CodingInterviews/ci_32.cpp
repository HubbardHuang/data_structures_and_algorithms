/*
题目：把数组排成最小的数

题目描述：
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组 {3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/

class Solution {
private:
    static bool compare(const string& left, const string& right) {
        string a = left + right;
        string b = right + left;
        return a < b;
    }

public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> buffer;
        for (int i = 0; i < numbers.size(); i++) {
            buffer.push_back(to_string(numbers[i]));
        }
        sort(buffer.begin(), buffer.end(), compare);
        string result = "";
        for (auto i = buffer.begin(); i != buffer.end(); i++) {
            result += *i;
        }
        return result;
    }
};