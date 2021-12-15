/*
Number: 31
Topic: Next Permutation
Date: 2021/12/7
Rate: Medium
https://leetcode.com/problems/next-permutation/

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

Constraints:
    * 1 <= nums.length <= 100
    * 0 <= nums[i] <= 100
*/
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                for (int j = n - 1; j > i; j--) {
                    if (nums[j] > nums[i]) {
                        swap(nums[i], nums[j]);
                        reverse(nums, i + 1, nums.size() - 1);
                        return;
                    }
                }
            }
        }
        reverse(nums, 0, nums.size() - 1);
    }

    void reverse(vector<int>& nums, int i, int j) {
        while (i < j) {
            swap(nums[i++], nums[j--]);
        }
    }
};