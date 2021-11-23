/*
Number: 228
Topic: Summary Ranges
Date: 2021/5/22
Rate: Easy
https://leetcode.com/problems/summary-ranges/


You are given a sorted unique integer array nums.

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

* "a->b" if a != b
* "a" if a == b

Constraints:

* 0 <= nums.length <= 20
* -231 <= nums[i] <= 231 - 1
* All the values of nums are unique.
* nums is sorted in ascending order.
*/



class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> out = {};
        if (nums.empty())
            return out;

        int head = nums[0];
        int tail = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != tail+1) {
                if (head != tail){
                    out.push_back(to_string(head) + "->" + to_string(tail));
                } else {
                    out.push_back(to_string(head));
                }
                head = nums[i];
                tail = nums[i];
            } else {
                tail = nums[i];
            }
        }
        if (head != tail)
            out.push_back(to_string(head) + "->" + to_string(tail));
        else
            out.push_back(to_string(head));
        return out;
    }
};