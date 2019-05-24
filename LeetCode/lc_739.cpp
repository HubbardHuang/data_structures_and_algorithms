/*
Title: Daily Temperatures

Description:
Given a list of daily temperatures T,
return a list such that,
for each day in the input,
tells you how many days you would have to wait
until a warmer temperature.
If there is no future day for which this is possible,
put 0 instead.

For example,
given the list of temperatures
T = [73, 74, 75, 71, 69, 72, 76, 73],
your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note:
The length of temperatures will be in the range [1, 30000].
Each temperature will be an integer in the range [30, 100].
*/

class Solution {
public:
    /* Decreasing stack */
    // vector<int> dailyTemperatures(const vector<int>& T) {
    //     vector<int> result(T.size(), 0);
    //     stack<int> s;
    //     for (decltype(T.size()) i = 0; i < T.size(); i++) {
    //         while (!s.empty() && T[i] > T[s.top()]) {
    //             int k = s.top();
    //             s.pop();
    //             result[k] = i - k;
    //         }
    //         s.push(i);
    //     }
    //     return result;
    // }

    /* Handle from tail to head */
    vector<int> dailyTemperatures(const vector<int>& T) {
        vector<int> result(T.size(), 0);
        for (decltype(T.size()) i = T.size() - 1; 0 <= i && i < T.size(); i--) {
            auto k = i + 1;
            while (k < T.size() && T[k] <= T[i]) {
                if (result[k] > 0) {
                    k = result[k] + k;
                } else {
                    k = T.size();
                }
            }
            if (k < T.size()) {
                result[i] = k - i;
            }
        }
        return result;
    }
};