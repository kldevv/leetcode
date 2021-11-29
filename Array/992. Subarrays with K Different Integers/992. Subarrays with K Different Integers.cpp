/*
Number: 994
Topic: Subarrays with K Different Integers
Date: 2021/11/26
Rate: Hard
https://leetcode.com/problems/subarrays-with-k-different-integers/

Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

Constraints:
* 1 <= nums.length <= 2 * 104
* 1 <= nums[i], k <= nums.length
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        /*
        1. # of Exactly(k) = # of AtMost(k) - # of AtMost(k-1)

        2. AtMost(k) => Sliding windows 
            Info:
                # of unique number in the current windows
                    (head(inclusive), tail(inclusive), uniqueCount, count)
            Satisfy (count <= k):
                a) record # of subarrays ends in tail
                b) move the tail
            Break (count > k):
                a) move the head
        */
        return subarraysWithAtMostKDistinct(nums, k) - subarraysWithAtMostKDistinct(nums, k - 1);
    }

    int subarraysWithAtMostKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int head = 0;
        int tail = 0;
        int countArr = 0;

        for (; tail < nums.size(); tail++) {
            k -= (!count[nums[tail]]++);
            while (head <= tail && k < 0) {     // Fix the invalid subarrays, if head = tail+1 meaning the array is empty
                k += (!--count[nums[head++]]);  // if head is a unique number in the array, uniqueCount -= 1
            }
            countArr += (tail - head + 1);
        }
        return countArr;
    }
};