/*
Number: 346
Topic: Moving Average from Data Stream
Date: 2021/7/23
Rate: Medium
https://leetcode.com/problems/moving-average-from-data-stream/

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Implement the MovingAverage class:
* MovingAverage(int size) Initializes the object with the size of the window size.
* double next(int val) Returns the moving average of the last size values of the stream.

Constraints:
* 1 <= size <= 1000
* -105 <= val <= 105
* At most 104 calls will be made to next.
*/

class MovingAverage {
public:
    queue<int> q;
    int capacity;
    int sum;
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->capacity = size;
        this->sum = 0;
    }
    
    double next(int val) {
        if (q.size() < capacity) {
            sum += val;
            q.push(val);
        }
        else {
            sum -= q.front();
            q.pop();
            sum += val;
            q.push(val);
        }

        return (double)sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */