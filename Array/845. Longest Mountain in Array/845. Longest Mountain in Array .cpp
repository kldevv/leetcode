/*
Number: 845
Topic: Longest Mountain in Array
Date: 2021/9/13
Rate: Medium
https://leetcode.com/problems/longest-mountain-in-array/

You may recall that an array arr is a mountain array if and only if:

    * arr.length >= 3
    * There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
        ** arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
        ** arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

Constraints:
    * 1 <= arr.length <= 104
    * 0 <= arr[i] <= 104

Follow up:
    * Can you solve it using only one pass?
    * Can you solve it in O(1) space?
*/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = 0;
        int maxLen = 0;

        while (i < n-1) {
            j = i;
            if (j < n-1 && arr[j] < arr[j+1]) {
                while (j < n-1 && arr[j] < arr[j+1]) 
                    j += 1;
                if (j < n-1 && j > 0 && arr[j-1] < arr[j] && arr[j] > arr[j+1]) {
                    while (j < n-1 && arr[j] > arr[j+1])
                        j += 1;
                    maxLen = max(maxLen, j-i+1);
                }
            }
            i = max(j, i+1);
        }
        return maxLen;
    }
};