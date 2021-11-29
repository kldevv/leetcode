/*
Number: 1249
Topic: Count Number of Nice Subarrays
Date: 2021/11/26
Rate: Medium
https://leetcode.com/problems/count-number-of-nice-subarrays/

Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

Constraints:
* 1 <= nums.length <= 50000
* 1 <= nums[i] <= 10^5
* 1 <= k <= nums.length
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        /*
        Exactly(k) = AtMost(k) - AtMost(k-1)

        %%%%%%%%%%%%%%%%%%%%%%%
        ! Complexity:
            - Time: O(n)
            - Space: O(1)

        */
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

    int atMostK(vector<int>& nums, int k) {
        /*
        Sliding windows;
        Info:
            - head (inclusive)
            - tail (inclusive)
            - # of odd number occurrence in the current array
                - var: number of odd
        Valid Action:
            - record number of valid subarray ends in tail
                - tail - head + 1
            - move tail by one
        Invalid Action:
            - move head by one
            
        %%%%%%%%%%%%%%%%%%%%%%%
        ! Complexity:
            - Time: O(n)
            - Space: O(1)
        */
        int head = 0;
        int tail = 0;
        int countValidArr = 0;
        for (; tail < nums.size(); tail++) {
            k -= (nums[tail] % 2);
            while (head <= tail && k < 0) {
                k += (nums[head++] % 2);
            }
            countValidArr += tail - head + 1;
        }
        return countValidArr;
    }
};