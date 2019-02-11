/*
题目：扑克牌顺子

题目描述：
如果牌能组成顺子就输出true，否则就输出false。
为了方便起见，你可以认为大小王是0。
*/

class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        sort(numbers.begin(), numbers.end());
        int joker = 0;
        int length = numbers.size();
        if (length < 2) {
            return false;
        }

        int prev = 0;
        int curr = 1;
        int joker_replace = 0;
        while (curr < length) {
            if (numbers[prev] == 0) {
                ++joker;
            } else if (numbers[prev] == numbers[curr]) {
                return false;
            } else if (numbers[prev] < numbers[curr] &&
                       numbers[curr] - numbers[prev] - 1 > joker) {
                return false;
            } else if (numbers[prev] < numbers[curr] &&
                       numbers[curr] - numbers[prev] - 1 <= joker) {
                joker -= (numbers[curr] - numbers[prev] - 1);
            }
            ++curr;
            ++prev;
        }
        if (joker > 0 && numbers[length - 1] == 13) {
            return false;
        } else {
            return true;
        }
    }
};