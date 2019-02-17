/*
题目：数据流中的中位数

题目描述：
如何得到一个数据流中的中位数？
如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
*/

class Solution {
private:
    int total = 0;
    priority_queue<int, vector<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

public:
    void Insert(int num) {
        ++total;
        if (max_heap.size() == min_heap.size()) {
            if (max_heap.empty()) {
                max_heap.push(num);
            } else {
                if (num < min_heap.top()) {
                    max_heap.push(num);
                } else {
                    int temp = min_heap.top();
                    min_heap.pop();
                    min_heap.push(num);
                    max_heap.push(temp);
                }
            }
        } else {
            if (max_heap.top() <= num) {
                min_heap.push(num);
            } else {
                int temp = max_heap.top();
                max_heap.pop();
                max_heap.push(num);
                min_heap.push(temp);
            }
        }
    }

    double GetMedian() {
        double median = 0;
        if (max_heap.size() == min_heap.size()) {
            median = (max_heap.top() + min_heap.top()) / 2.0;
        } else {
            median = (double)max_heap.top();
        }
        return median;
    }
};