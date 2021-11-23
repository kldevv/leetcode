/*
Number: 33
Topic: Search in Rotated Sorted Array
Date: 2021/5/6
Rate: Medium
https://leetcode.com/problems/search-in-rotated-sorted-array/

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

Constraints:
* 1 <= nums.length <= 5000
* -104 <= nums[i] <= 104
* All values of nums are unique.
* nums is guaranteed to be rotated at some pivot.
* -104 <= target <= 104


tc / Olog(n)
*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 用 binary search 找 rotation 的點（也就是最小值）
        int l = 0, r = nums.size() - 1;
        while (r > l){
            int m = l + (r-l)/2;
            if (nums[m] > nums[r]){
                l = m + 1;
            } else {
                r = m;
            }
        }
        // 看是要往最小值的左邊找還是右邊找，拿到的會是一個正常的 ascending sorted array
        int k = l;
        cout << k;
        r = nums.size() - 1;
        l = 0;
        if ((nums[k] <= target) && (nums[r] >= target)){
            l = k;
        } else {
            r = k;
        }
        // good old binary search it is!
        while (l <= r){
            int m = l + (r-l)/2;
            if (nums[m] == target) return m;
            else if (nums[m] > target){
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
};


