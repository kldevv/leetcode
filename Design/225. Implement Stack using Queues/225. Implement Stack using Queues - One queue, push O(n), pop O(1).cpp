/*
Number: 225
Topic: Implement Stack using Queues - One queue, pushO()
Date: 2021/12/4
Rate: Easy
https://leetcode.com/problems/implement-stack-using-queues/

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:
    * void push(int x) Pushes element x to the top of the stack.
    * int pop() Removes the element on the top of the stack and returns it.
    * int top() Returns the element on the top of the stack.
    * boolean empty() Returns true if the stack is empty, false otherwise.

Constraints:
    * 1 <= x <= 9
    * At most 100 calls will be made to push, pop, top, and empty.
    * All the calls to pop and top are valid.

Follow-up: Can you implement the stack using only one queue?
*/
#include <algorithm>
#include <queue>

using namespace std;

class MyStack {
   private:
    queue<int> container;

   public:
    MyStack() {
        /*
        A should be [n1, n2, n3, n4, ...., ]
        n1 is the latest element push in A, so on so forth.
        */
    }

    void push(int x) {
        /*
        When push a new element n0
        => A = [n1, n2, n3, n4, ...., nN, n0]

        Pop front and push to end N times
        A should be [n0, n1, n2, n3, n4, ...., nN]
        */
        container.push(x);
        for (int i = 0; i < container.size() - 1; i++) {
            container.push(container.front());
            container.pop();
        }
    }

    int pop() {
        /*
        pop front;
        */
        int val = container.front();
        container.pop();
        return val;
    }

    int top() {
        /*
        front
        */
        return container.front();
    }

    bool empty() {
        return container.size() == 0;
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