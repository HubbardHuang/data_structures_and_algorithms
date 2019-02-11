/*
题目：翻转单词顺序列

题目描述：
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
正确的句子应该是“I am astudent.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
*/

class Solution {
public:
    string ReverseSentence(string& str) {
        int length = str.size();
        if (length == 1) {
            return str;
        }
        for (int i = 0, head = 0, tail = 0; i < length; i++) {
            if ((str[i] == ' ' && i != 0) || i == length - 1) {
                tail = (i == length - 1) ? length : i;
                reverse(str.begin() + head, str.begin() + tail);
                head = i + 1;
            }
        }
        reverse(str.begin(), str.end());
        return str;
    }
};