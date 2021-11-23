/*
Number: 322
Topic: Coin Change
Date: 2021/6/22
Rate: Easy
https://leetcode.com/problems/coin-change/

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

* MinStack() initializes the stack object.
* void push(val) pushes the element val onto the stack.
* void pop() removes the element on the top of the stack.
* int top() gets the top element of the stack.
* int getMin() retrieves the minimum element in the stack.

Constraints:
* -2^31 <= val <= 2^31 - 1
* Methods pop, top and getMin operations will always be called on non-empty stacks.
* At most 3 * 104 calls will be made to push, pop, top, and getMin.

*/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> normalStk;
    stack<int> minValue;
    MinStack() {
    }
    
    void push(int val) {
        normalStk.push(val);
        if (minValue.empty() || val <= getMin())
            minValue.push(val);
    }
    
    void pop() {
        if (normalStk.top() == getMin())
            minValue.pop();
        normalStk.pop();
    }
    
    int top() {
        return normalStk.top();
    }
    
    int getMin() {
        return minValue.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */