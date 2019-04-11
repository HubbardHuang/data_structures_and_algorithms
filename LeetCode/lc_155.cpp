/*
Title: Min Stack

Description:
Design a stack that supports push, pop, top,
and retrieving the minimum element in constant time.
    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

class MinStack {
private:
    stack<int> number_stack;
    stack<int> min_stack;

public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        number_stack.push(x);
        if (min_stack.empty() || min_stack.top() >= x) {
            min_stack.push(x);
        }
    }

    void pop() {
        if (number_stack.empty()) {
            return;
        }
        int deleted = number_stack.top();
        number_stack.pop();
        if (!min_stack.empty() && deleted == min_stack.top()) {
            min_stack.pop();
        }
    }

    int top() {
        if (number_stack.empty()) {
            return -1;
        }
        return number_stack.top();
    }

    int getMin() {
        if (min_stack.empty()) {
            return -1;
        }
        return min_stack.top();
    }
};

class MinStack {
private:
    int min;
    stack<int> number_stack;

public:
    /** initialize your data structure here. */
    MinStack() {
        min = INT_MAX; // minimum value of "int"
    }

    void push(int x) {
        if (x <= min) { // ensure x >= min
            number_stack.push(min);
            min = x;
        }
        number_stack.push(x);
    }

    void pop() {
        if (number_stack.top() > min) {
            number_stack.pop();
        } else /* number_stack.top() == min */ {
            number_stack.pop();
            min = number_stack.top();
            number_stack.pop();
        }
    }

    int top() { return number_stack.top(); }

    int getMin() { return min; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */