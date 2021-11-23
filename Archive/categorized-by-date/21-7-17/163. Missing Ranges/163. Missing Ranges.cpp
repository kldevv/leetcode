/*
Number: 163
Topic: Missing Ranges
Date: 2021/7/17
Rate: Easy
https://leetcode.com/problems/missing-ranges/

You are given an inclusive range [lower, upper] and a sorted unique integer array nums, where all elements are in the inclusive range.

A number x is considered missing if x is in the range [lower, upper] and x is not in nums.

Return the smallest sorted list of ranges that cover every missing number exactly. That is, no element of nums is in any of the ranges, and each missing number is in one of the ranges.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b

Constraints:
* -109 <= lower <= upper <= 109
* 0 <= nums.length <= 100
* lower <= nums[i] <= upper
* All the values of nums are unique.
*/

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> out;
        int next = lower;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < next)
                continue;
            if (nums[i] != next)
                out.push_back(getRange(next, nums[i]-1));
            next = nums[i]+1;
        }

        if (next <= upper)
            out.push_back(getRange(next, upper));

        return out;
    }

    string getRange(int lower, int upper) {
        return (lower == upper) ? to_string(lower) : to_string(lower) + "->" + to_string(upper);
    }
};