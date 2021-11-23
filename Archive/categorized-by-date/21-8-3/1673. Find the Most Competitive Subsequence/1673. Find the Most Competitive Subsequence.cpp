/*
Number: 1673
Topic: Find the Most Competitive Subsequence
Date: 2021/8/3
Rate: Medium
https://leetcode.com/problems/find-the-most-competitive-subsequence/

Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.

An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.

We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position where a and b differ, subsequence a has a number less than the corresponding number in b. For example, [1,3,4] is more competitive than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.

Constraints:
* 1 <= nums.length <= 105
* 0 <= nums[i] <= 109
* 1 <= k <= nums.length
*/
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> competitors;

        for (int i = 0; i < n; i++) {
            while (competitors.size() && competitors.size()+(n-i) > k && competitors.back() > nums[i])
                competitors.pop_back();
            if (competitors.size() < k)
                competitors.push_back(nums[i]);
        }
        return competitors;
    }
};