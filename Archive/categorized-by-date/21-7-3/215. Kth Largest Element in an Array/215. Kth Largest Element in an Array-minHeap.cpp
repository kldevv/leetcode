/*
Number: 215
Topic: Kth Largest Element in an Array
Date: 2021/7/3
Rate: Medium
https://leetcode.com/problems/kth-largest-element-in-an-array/

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Constraints:
* 1 <= k <= nums.length <= 104
* -104 <= nums[i] <= 104

*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        // min-heap solution
        
        // tc: O(nlogK) for takes n operation to insert the value and heap.size has maximum of k
        // insert heap takes O(logT) where T is heap.size()
        for (const int& num : nums) {
            pq.push(num);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};