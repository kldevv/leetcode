/*
Number: 496
Topic: Next Greater Element I
Date: 2021/8/3
Rate: Easy
https://leetcode.com/problems/next-greater-element-i/

The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

Constraints:
* 1 <= nums1.length <= nums2.length <= 1000
* 0 <= nums1[i], nums2[i] <= 104
* All integers in nums1 and nums2 are unique.
* All the integers of nums1 also appear in nums2.
 
Follow up: Could you find an O(nums1.length + nums2.length) solution?
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        stack<int> nextGreater;
        for (int i = nums2.size()-1; i >= 0; i--) {
            while (nextGreater.size() && nextGreater.top() < nums2[i]) {
                nextGreater.pop();
            }
            umap[nums2[i]] = (nextGreater.size()) ? nextGreater.top() : -1;
            nextGreater.push(nums2[i]);
        }

        vector<int> out(nums1.size(), 0);
        for (int j = 0; j < nums1.size(); j++)
            out[j] = umap[nums1[j]];
        return out;
    }
};