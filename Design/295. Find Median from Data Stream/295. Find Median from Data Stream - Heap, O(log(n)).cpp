/*
Number: 295
Topic: Combination Sum - Heap, O(log(n))
Date: 2021/12/5
Rate: Medium
https://leetcode.com/problems/combination-sum/

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.
    * For example, for arr = [2,3,4], the median is 3.
    * For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

Implement the MedianFinder class:
    * MedianFinder() initializes the MedianFinder object.
    * void addNum(int num) adds the integer num from the data stream to the data structure.
    * double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

Constraints:
    * 1 <= candidates.length <= 30
    * 1 <= candidates[i] <= 200
    * All elements of candidates are distinct.
    * 1 <= target <= 500
*/

#include <functional>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
   private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;
    int n;
    double median;

   public:
    MedianFinder() {
        /*
        maxHeap => lowerHalf
        minHeap => upperHalf
        */
        n = 0;
    }

    void addNum(int num) {
        /*
        maxHeap.push(num)

        while (maxHeap.size() > minHeap.size()+1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        */
        if (num > median) {
            minHeap.push(num);
        } else {
            maxHeap.push(num);
        }
        while (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        while (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        n += 1;
        if (n % 2) {
            median = (double)maxHeap.top();
        } else {
            median = ((double)maxHeap.top() + (double)minHeap.top()) / (double)2;
        }
    }

    double findMedian() {
        /*
        if n % 2 == 1:
            return minHeap.top();
        else
            return (minHeap.top() + maxHeap.top()) / 2;
        */
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */