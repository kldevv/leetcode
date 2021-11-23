/*
Number: 360
Topic: Sort Transformed Array
Date: 2021/7/21
Rate: Medium
https://leetcode.com/problems/sort-transformed-array/

Given a sorted integer array nums and three integers a, b and c, apply a quadratic function of the form f(x) = ax2 + bx + c to each element nums[i] in the array, and return the array in a sorted order.

Constraints:
* 1 <= nums.length <= 200
* -100 <= nums[i], a, b, c <= 100
* nums is sorted in ascending order.

Follow up: Could you solve it in O(n) time?
*/

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> out(n, 0);

        int left = 0, right = n-1;
        for (int i = 0; i < n; i++) {
            if (a < 0) {
                out[i] = (func(nums[left], a, b, c) <= func(nums[right], a, b, c)) ? func(nums[left++], a, b, c) : func(nums[right--], a, b, c);
            }
            else {
                out[n-i-1] = (func(nums[left], a, b, c) > func(nums[right], a, b, c)) ? func(nums[left++], a, b, c) : func(nums[right--], a, b, c);
            }
        }
        return out;
    }

    int func(int x, int a, int b, int c) {
        return a*pow(x, 2) + b*x + c;
    }
};