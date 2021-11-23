/*
Number: 1539
Topic: Kth Missing Positive Number
Date: 2021/10/19
Rate: Easy
https://leetcode.com/problems/kth-missing-positive-number/

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Find the kth positive integer that is missing from this array.

Constraints:
    * 1 <= arr.length <= 1000
    * 1 <= arr[i] <= 1000
    * 1 <= k <= 1000
    * arr[i] < arr[j] for 1 <= i < j <= arr.length
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (arr[mid] - mid - 1 >= k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left + k;
    }
};