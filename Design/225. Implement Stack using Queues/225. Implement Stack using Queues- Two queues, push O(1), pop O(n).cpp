/*
Number: 225
Topic: Implement Stack using Queues - Two queues, push O(1), pop O(n)
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
    queue<int> A;
    queue<int> B;

   public:
    MyStack() {
    }

    void push(int x) {
        /*
        A.push(x)
        */
        A.push(x);
    }

    int pop() {
        /*
        while (A.size() > 1)
            B.push(A.front())
            A.pop()
        A.pop()
        swap(A, B)
        */
        while (A.size() > 1) {
            B.push(A.front());
            A.pop();
        }
        int top = A.front();
        A.pop();
        swap(A, B);
        return top;
    }

    int top() {
        /*
        while (A.size() > 1)
            B.push(A.front())
            A.pop()
        return A.front()
        B.push(A)
        A.pop()
        swap(A, B)
        */
        while (A.size() > 1) {
            B.push(A.front());
            A.pop();
        }
        int top = A.front();
        B.push(A.front());
        A.pop();
        swap(A, B);
        return top;
    }

    bool empty() {
        /*
        return size == 0?
        */
        return A.size() == 0;
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