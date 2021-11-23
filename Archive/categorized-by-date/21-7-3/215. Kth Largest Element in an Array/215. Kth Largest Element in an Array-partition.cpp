/*
Number: 215
Topic: Kth Largest Element in an Array
Date: 2021/7/3
Rate: Medium
https://leetcode.com/problems/kth-largest-element-in-an-array/

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Constraints:
* 1 <= k <= nums.length <= 104
* -104 <= nums[i] <= 104

*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int idx = 0;
        int n = nums.size();
        int left = 0, right = n-1;
        // quicksort O(n)
        // do a partial sort
        // 只用 pivot 繼續分裂 k 在的那一邊

        while (true) {
            idx = partition(nums, left, right);
            if (idx == n-k)
                return nums[n-k];
            if (idx < n-k)
                left = idx+1;
            if (idx > n-k)
                right = idx-1;
        }
    }
private:
    int partition(vector<int>& nums, int left, int right) {
        int last = right;
        int pivot = nums[right--];
        while (left <= right) {
            if (nums[left] > pivot && nums[right] < pivot)
                swap(nums[left++], nums[right--]);
            if (nums[left] <= pivot)
                left++;
            if (nums[right] >= pivot)
                right--;
        }
        swap(nums[last], nums[left]);

        return left;
    }
};