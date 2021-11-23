/*
Number: 324
Topic: Wiggle Sort II
Date: 2021/7/13
Rate: Medium
https://leetcode.com/problems/wiggle-sort-ii/

Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

You may assume the input array always has a valid answer.

Constraints:
* 1 <= nums.length <= 5 * 104
* 0 <= nums[i] <= 5000
* It is guaranteed that there will be an answer for the given input nums.
 

Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto midPtr = nums.begin() + n/2;
        nth_element(nums.begin(), midPtr, nums.end());
        int mid = *midPtr;
        // 把 array 以中位數來分成兩個部分
        // 大於中位數，小於中位數 (中位數可能被丟在第一部分的最後，或是第二部份，因為題目限制 wiggle 從小的開始，所以一定在第一部分，不然就沒辦法行成 wiggle，小於中位數的值一定要比大於等於中位數的值多一)

        // 3-way partition
        int i = 0, j = 0, t = n-1;
        while (j <= t) {
            int val = getWiggleIndex(j, nums);

            if (val > mid) {
                swapWiggleIndex(i++, j++, nums);
            }
            else if (val < mid) {
                swapWiggleIndex(j, t--, nums);
            }
            else { // nums[j] == mid
                j++;
            }
        }
    }

    // 前半的 index 放在基數為，後半的放在偶數位
    void swapWiggleIndex(int i, int j, vector<int>& nums) {
        int n = nums.size();
        swap(nums[((i*2)+1) % (n|1)], nums[((j*2)+1) % (n|1)]);
    }

    int getWiggleIndex(int i, const vector<int>& nums) {
        int n = nums.size();
        return nums[((i*2)+1) % (n|1)];
    }

};