/*
Number: 35
Topic: Search Insert Position
Date: 2021/5/5
Rate: Easy
https://leetcode.com/problems/search-insert-position/

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

tc / Olog(n)
*/


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;

        while (start <= end){
            int half = start + (end-start) / 2;
            
            if (nums[half] == target) return half;
            else if (nums[half] > target){
                end = half - 1;
            }
            else {
                start = half + 1;
            }
        }
        return start;
    }
};
