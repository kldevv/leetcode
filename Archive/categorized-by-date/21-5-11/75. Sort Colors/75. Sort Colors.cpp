/*
Number: 75
Topic: Sort Colors
Date: 2021/5/11
Rate: Medium
https://leetcode.com/problems/sort-colors/

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Constraints:

* n == nums.length
* 1 <= n <= 300
* nums[i] is 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?


*/

// 用 counting sort 解決
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroCount = 0, oneCount = 0, twoCount = 0;
        for (const int& num : nums) {
            switch (num) {
                case 0:
                    zeroCount++;
                    break;
                case 1:
                    oneCount++;
                    break;
                default:
                    twoCount++;
                    break;
            }
        }

        for (int& num : nums) {
            if (zeroCount) {
                num = 0;
                zeroCount--;
            } else if (oneCount) {
                num = 1;
                oneCount--;
            } else if (twoCount) {
                num = 2;
                twoCount--;
            } else break;
        }
    }
};

