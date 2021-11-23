/*
Number: 1838
Topic: Frequency of the Most Frequent Element
Date: 2021/6/16
Rate: Medium
https://leetcode.com/problems/frequency-of-the-most-frequent-element/

The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.

Constraints:
* 1 <= nums.length <= 105
* 1 <= nums[i] <= 105
* 1 <= k <= 105
*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 0, _max = 0, count = 0;
        long sum = 0;

        for (; j < nums.size(); j++) {
            sum += nums[j];
            count += 1;
            while (i < j && sum + k < static_cast<long>(nums[j])*count) {
                sum -= nums[i++];
                count -= 1;
            }
            _max = max(_max, count);
        }
        return _max;
    }
};