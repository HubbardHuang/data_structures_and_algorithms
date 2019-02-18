/*
题目：滑动窗口的最大值

题目描述：
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}；
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
{[2,3,4],2,6,2,5,1}，{2,[3,4,2],6,2,5,1}，{2,3,[4,2,6],2,5,1}，
{2,3,4,[2,6,2],5,1}，{2,3,4,2,[6,2,5],1}，{2,3,4,2,6,[2,5,1]}。
*/

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> result;
        if (size == 0 || size > num.size()) {
            result.clear();
            return result;
        }
        queue<int> window;
        queue<int> max;

        // 窗口初始化
        for (int i = 0; i < num.size() && i < size; i++) {
            window.push(num[i]);
            if (max.empty() || max.back() <= num[i]) {
                max.push(num[i]);
            }
        }
        result.push_back(max.back());

        // 滑动窗口的同时寻找最值
        for (int i = size; i < num.size(); i++) {
            int leave = window.front();
            window.pop();
            if (leave == max.front()) {
                max.pop();
                if (max.empty()) {
                    int count = window.size();
                    for (int i = 0; i < count; i++) {
                        int temp = window.front();
                        window.pop();
                        if (max.empty() || max.back() <= temp) {
                            max.push(temp);
                        }
                        window.push(temp);
                    }
                }
            }
            window.push(num[i]);
            if (max.empty() || max.back() <= num[i]) {
                max.push(num[i]);
            }
            result.push_back(max.back());
        }

        return result;
    }
};