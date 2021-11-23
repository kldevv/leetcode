/*
Number: 1249
Topic: Count Number of Nice Subarrays
Date: 2021/8/4
Rate: Medium
https://leetcode.com/problems/count-number-of-nice-subarrays/

Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

Constraints:
* 1 <= nums.length <= 50000
* 1 <= nums[i] <= 10^5
* 1 <= k <= nums.length
*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k-1);
    }

    int atMostK(const vector<int>& nums, int k) {
        int j = 0;
        int out = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2)
                k--;
            while (k < 0) {
                if (nums[j++] % 2)
                    k++;
            }
            out += i - j + 1;
        }
        return out;        
    }
};