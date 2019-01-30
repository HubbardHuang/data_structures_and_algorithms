/*
题目：用两个栈实现队列

题目描述：
用两个栈来实现一个队列，完成队列的Push和Pop操作。
队列中的元素为int类型。
*/

class Solution {
public:
    void push(int node) { pushing_stack.push(node); }

    int pop() {
        if (popping_stack.empty()) {
            while (!pushing_stack.empty()) {
                int temp = pushing_stack.top();
                pushing_stack.pop();
                popping_stack.push(temp);
            }
        }
        int popped = popping_stack.top();
        popping_stack.pop();
        return popped;
    }

private:
    stack<int> pushing_stack;
    stack<int> popping_stack;
};