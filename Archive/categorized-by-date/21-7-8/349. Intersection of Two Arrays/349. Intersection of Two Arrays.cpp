/*
Number: 349
Topic: Intersection of Two Arrays
Date: 2021/7/8
Rate: Easy
https://leetcode.com/problems/intersection-of-two-arrays/

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Constraints:
* 1 <= nums1.length, nums2.length <= 1000
* 0 <= nums1[i], nums2[i] <= 1000
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end());
        vector<int> out;
        for (int num : nums2) {
            if (set.count(num)) {
                set.erase(num);
                out.push_back(num);
            }
        }
        return out;
    }
};