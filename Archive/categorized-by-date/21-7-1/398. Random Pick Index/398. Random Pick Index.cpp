/*
Number: 398
Topic: Random Pick Index
Date: 2021/7/1
Rate: Medium
https://leetcode.com/problems/random-pick-index/

Given an integer array nums with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the array nums.
int pick(int target) Picks a random index i from nums where nums[i] == target. If there are multiple valid i's, then each index should have an equal probability of returning.

Constraints:
* 1 <= nums.length <= 2 * 104
* -2^31 <= nums[i] <= 2^31 - 1
* target is an integer from nums.
* At most 10^4 calls will be made to pick.

*/

class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    // base on reservoir sampling
    int pick(int target) {
        int count = 0;
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != target)
                continue;
            if (count++ == 0)
                result = i;
            if (!(rand() % count))
                result = i;
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */