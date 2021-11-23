/*
Number: 239
Topic: Sliding Window Maximum
Date: 2021/8/2
Rate: Hard
https://leetcode.com/problems/constrained-subsequence-sum/

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Constraints:
* 1 <= nums.length <= 105
* -104 <= nums[i] <= 104
* 1 <= k <= nums.length
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> candidates;
        vector<int> out;
        for (int i = 0; i < nums.size(); i++) {
            while (!candidates.empty() && (i-candidates.front() >= k))
                candidates.pop_front();
            while (!candidates.empty() && nums[candidates.back()] <= nums[i])
                candidates.pop_back();
            candidates.push_back(i);
            if (i >= k-1)
                out.push_back(nums[candidates.front()]);
        }
        return out;
    }
};