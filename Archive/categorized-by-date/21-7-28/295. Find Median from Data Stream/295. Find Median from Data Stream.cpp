/*
Number: 295
Topic: Find Median from Data Stream
Date: 2021/7/28
Rate: Hard
https://leetcode.com/problems/find-median-from-data-stream/

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

Implement the MedianFinder class:
* MedianFinder() initializes the MedianFinder object.
* void addNum(int num) adds the integer num from the data stream to the data structure.
* double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

Constraints:
* -105 <= num <= 105
* There will be at least one element in the data structure before calling findMedian.
* At most 5 * 104 calls will be made to addNum and findMedian.
 

Follow up:
* If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
* If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

*/
class MedianFinder {
private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        //
    }
    
    void addNum(int num) {
        small.push(num);
        big.push(small.top());
        small.pop();

        if (small.size() < big.size()) {
            small.push(big.top());
            big.pop();
        }
    }
    
    double findMedian() {
        return (small.size() > big.size()) ? small.top() : small.top() + (big.top()-small.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */