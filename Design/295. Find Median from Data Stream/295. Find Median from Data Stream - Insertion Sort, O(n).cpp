/*
Number: 295
Topic: Combination Sum - Insertion Sort, O(n)
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

#include <algorithm>
#include <vector>

using namespace std;

class MedianFinder {
   private:
    vector<int> container;

   public:
    MedianFinder() {
        /*
        arr = [n0, n1, ..., nN]
        median is arr[arr.size()/2] or mean(arr[arr.size()/2] + arr[(arr.size()+1)/2])
        */
    }

    void addNum(int num) {
        /*
        1. Binary Search find location of num.
        2. Insert num.
        */
        vector<int>::iterator insertionPos = lower_bound(container.begin(), container.end(), num);
        container.insert(insertionPos, num);
    }

    double findMedian() {
        if (container.size() % 2 == 1) {
            // odd
            return (double)container[container.size() / 2];
        } else {
            // even
            int lowerHalf = container[(container.size() - 1) / 2];
            int higherHalf = container[container.size() / 2];
            return (double)lowerHalf + (double)(higherHalf - lowerHalf) / (double)2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */