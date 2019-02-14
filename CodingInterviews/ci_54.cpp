/*
题目：字符流中第一个不重复的字符

题目描述：
请实现一个函数用来找出字符流中第一个只出现一次的字符。
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
*/

class Solution {
public:
    // Insert one char from stringstream
    string buffer;
    map<char, int> count;
    void Insert(char ch) {
        buffer.push_back(ch);
        count[ch]++;
    }
    // return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        for (auto i = buffer.begin(); i != buffer.end(); i++) {
            if (count[*i] == 1) {
                return *i;
            }
        }
        return '#';
    }
};