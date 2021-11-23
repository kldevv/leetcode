/*
Number: 448
Topic: Find All Numbers Disappeared in an Array
Date: 2021/11/17
Rate: Easy
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

Constraints:
    * n == nums.length
    * 1 <= n <= 105
    * 1 <= nums[i] <= n

* Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
*/
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        for (int num : nums) {
            int hash = (num % (n + 1)) - 1;
            nums[hash] += (n + 1);
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (nums[i] < (n + 1))
                result.push_back(i + 1);
        }
        return result;
    }
};
