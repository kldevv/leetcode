/*
Number: 622
Topic: Design Circular Queue
Date: 2021/11/6
Rate: Medium
https://leetcode.com/problems/design-circular-queue/

Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implementation the MyCircularQueue class:
    * MyCircularQueue(k) Initializes the object with the size of the queue to be k.
    * int Front() Gets the front item from the queue. If the queue is empty, return -1.
    * int Rear() Gets the last item from the queue. If the queue is empty, return -1.
    * boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
    * boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
    * boolean isEmpty() Checks whether the circular queue is empty or not.
    * boolean isFull() Checks whether the circular queue is full or not.

You must solve the problem without using the built-in queue data structure in your programming language. 

Constraints:
    * 1 <= k <= 1000
    * 0 <= value <= 1000
    * At most 3000 calls will be made to enQueue, deQueue, Front, Rear, isEmpty, and isFull.
*/

class MyCircularQueue {
private:
    vector<int> container;
    int capacity;
    int size;
    int head;
    int tail;
public:
    MyCircularQueue(int k) {
        this->capacity = k;
        this->container = vector<int>(k, 0);
        this->size = 0;
        this->head = 0;
        this->tail = -1;
    }
    
    bool enQueue(int value) {
        if (size == capacity)
            return false;
        tail = (tail + 1) % capacity;
        container[tail] = value;
        size += 1;
        return true;
    }
    
    bool deQueue() {
        if (size <= 0)
            return false;
        head = (head + 1) % capacity;
        size -= 1;
        return true;
    }
    
    int Front() {
        return (size > 0) ? container[head] : -1;
    }
    
    int Rear() {
        return (size > 0) ? container[tail] : -1;
    }
    
    bool isEmpty() {
        return !size;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */