/*
Number: 532
Topic: K-diff Pairs in an Array
Date: 2021/9/7
Rate: Medium
https://leetcode.com/problems/k-diff-pairs-in-an-array/

Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

    * 0 <= i < j < nums.length
    * |nums[i] - nums[j]| == k

Notice that |val| denotes the absolute value of val.

Constraints:
    * 1 <= nums.length <= 104
    * -107 <= nums[i] <= 107
    * 0 <= k <= 107
*/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int result = 0;
        for (const int& num : nums)
            umap[num] += 1;

        for (pair<int, int> p : umap) {
            if ((k == 0 && p.second > 1) || (k > 0 && umap.count(p.first+k)))
               result += 1;  
        }
        return result;
    }
};
