/*
Number: 376
Topic: Wiggle Subsequence
Date: 2021/5/22
Rate: Medium
https://leetcode.com/problems/wiggle-subsequence/

A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

* For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
* In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.

A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

Given an integer array nums, return the length of the longest wiggle subsequence of nums.

Constraints:

* 1 <= nums.length <= 1000
* 0 <= nums[i] <= 1000

Follow up: Could you solve this in O(n) time?
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int down = 1, up = 1;
        // down 代表以 i-1 元素做結尾為負值最長 wiggle 的長度
        // up 代表以 i-1 元素做結尾為負值最長 wiggle 的長度
        
        // 這個概念等於建立兩個 wiggle array
        // e.g. [1, 4, 5, 7, 6, 4, 6]
        // up = (1, 4) 如果是遞增
        // up = (1, 5) 就不斷後推
        // up = (1, 7) 到最大的元素
        // down << up << (6)
        // down = (1, 7, 6) 如果是遞減
        // down = (1, 7, 4) 就不斷後退到最小的元素
        // up << down << (6)
        // up = (1, 7, 4, 6)

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1])
                up = down + 1;
            else if (nums[i] < nums[i-1])
                down = up + 1;
        }
        return max(up, down);
    }
};