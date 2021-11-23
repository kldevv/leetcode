/*
Number: 239
Topic: Sliding Window Maximum
Date: 2021/11/15
Rate: Hard
https://leetcode.com/problems/sliding-window-maximum/

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Constraints:
    * 1 <= nums.length <= 105
    * -104 <= nums[i] <= 104
    * 1 <= k <= nums.length
*/

#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // maxValIdx: windows of possible candidates; the biggest element be the front, and the closest element in the back
        // candidates in the back should not be larger than the candidate in the front. Otherwise candidate in the front is no longer a candidate and should be popped off.

        // candidate should stay at the moving windows, namely: (i - candIdx + 1) <= k

        deque<int> maxValIdx;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            while (maxValIdx.size() && nums[maxValIdx.back()] <= nums[i]) {
                maxValIdx.pop_back();
            }
            maxValIdx.push_back(i);

            while (maxValIdx.size() && (i - maxValIdx.front() + 1) > k) {
                maxValIdx.pop_front();
            }

            if (i >= k - 1) {
                result.push_back(nums[maxValIdx.front()]);
            }
        }
        return result;
    }
};