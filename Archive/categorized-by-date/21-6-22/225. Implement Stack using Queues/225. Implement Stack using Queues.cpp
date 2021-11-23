/*
Number: 225
Topic: Implement Stack using Queues
Date: 2021/6/22
Rate: Easy
https://leetcode.com/problems/implement-stack-using-queues/

Implement a last in first out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal queue (push, top, pop, and empty).

Implement the MyStack class:
* void push(int x) Pushes element x to the top of the stack.
* int pop() Removes the element on the top of the stack and returns it.
* int top() Returns the element on the top of the stack.
* boolean empty() Returns true if the stack is empty, false otherwise.

Notes:
* You must use only standard operations of a queue, which means only push to back, peek/pop from front, size, and is empty operations are valid.
* Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue), as long as you use only a queue's standard operations.


Constraints:
* 1 <= x <= 9
* At most 100 calls will be made to push, pop, top, and empty.
* All the calls to pop and top are valid.

*/

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;

    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size()-1; i++) {
            // 把前面的值都 pop 掉然後再 push 到尾巴，這樣最新 push 進的值就是第一個
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = top();
        q.pop();
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */