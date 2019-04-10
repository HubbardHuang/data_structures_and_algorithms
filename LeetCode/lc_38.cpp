/*
Title: Count and Say

Description:
The count-and-say sequence is the sequence of integers with the first five terms as
following:
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n where 1 ≤ n ≤ 30,
generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:
Input: 1
Output: "1"

Example 2:
Input: 4
Output: "1211"
*/

class Solution {
public:
    string countAndSay(int n) {
        string source = "1";
        if (n == 1) {
            return source;
        }
        for (int i = 0; i < n; i++) {
            int length = source.size();
            if (length == 1) {
                source = "11";
                i++;
                continue;
            }
            char prev = source[0];
            string next = "";
            int count = 1;
            for (int k = 1; k < length; k++) {
                if (source[k] == prev) {
                    count++;
                }
                if (k == length - 1 || source[k] != prev) {
                    next += to_string(count);
                    next.push_back(source[k - 1]);
                    count = 1;
                    if (source[k] != prev && k == length - 1) {
                        next.push_back('1');
                        next.push_back(source[k]);
                    }
                    prev = source[k];
                }
            }
            source = next;
        }
        return source;
    }
};