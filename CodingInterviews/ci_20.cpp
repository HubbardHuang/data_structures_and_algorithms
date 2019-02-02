/*
题目：包含min函数的栈

题目描述：
定义栈的数据结构，
请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/

class Solution {
private:
    stack<int> st, mi;

public:
    void push(int value) {
        st.push(value);
        if (st.empty() || mi.empty() || value <= mi.top()) {
            mi.push(value);
        }
    }
    void pop() {
        int top_element = st.top();
        st.pop();
        if (top_element == mi.top()) {
            mi.pop();
        }
    }
    int top() {
        int top_element = st.top();
        return top_element;
    }
    int min() {
        int min_element = mi.top();
        return min_element;
    }
};