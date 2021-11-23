/*
Number: 88
Topic: Move Zeroes
Date: 2021/5/22
Rate: Easy
https://leetcode.com/problems/move-zeroes/

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Constraints:

* 1 <= nums.length <= 104
* -231 <= nums[i] <= 231 - 1

Follow up: Could you minimize the total number of operations done?
*/

class Solution {
public:
    // tc: O(n)
    void moveZeroes(vector<int>& nums) {
        int idx = 0, counter = 0;
        // 把非零數字都往前丟，最後把剩下的都填 0
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i])
                nums[idx++] = nums[i];
            else 
                counter++;
        }
        for (int i = nums.size()-1; counter > 0; i--, counter--) {
            nums[i] = 0;
        }
    }
};