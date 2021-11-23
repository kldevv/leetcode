/*
Number: 350
Topic: Intersection of Two Arrays II
Date: 2021/7/9
Rate: Easy
https://leetcode.com/problems/intersection-of-two-arrays-ii/

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Constraints:
* 1 <= nums1.length, nums2.length <= 1000
* 0 <= nums1[i], nums2[i] <= 1000

Follow up:

* What if the given array is already sorted? How would you optimize your algorithm?
* What if nums1's size is small compared to nums2's size? Which algorithm is better?
* What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        // 等於把 nums1 前面幾個元素改成 intersection，再把原本後面的東西刪掉
        // set_intersection，修改 result iterator 的結果，在回傳 result iterator+1
        // erase(iter1, iter2) 刪除 iter1 和 iter2 中間的元素
        nums1.erase(set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums1.begin()), nums1.end());
        return nums1;
    }
};