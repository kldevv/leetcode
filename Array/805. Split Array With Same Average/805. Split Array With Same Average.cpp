/*
Number: 805
Topic: Split Array With Same Average
Date: 2021/9/9
Rate: Hard
https://leetcode.com/problems/split-array-with-same-average/

You are given an integer array nums.

You should move each element of nums into one of the two arrays A and B such that A and B are non-empty, and average(A) == average(B).

Return true if it is possible to achieve that and false otherwise.

Note that for an array arr, average(arr) is the sum of all the elements of arr over the length of arr.

Constraints:
    * 1 <= nums.length <= 30
    * 0 <= nums[i] <= 104
*/

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int totalLength = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        vector<int> existSubsetSum(totalSum+1, 0);
        existSubsetSum[0] = 1;

        for (const int& num : nums) {
            for (int subsetSum = totalSum; subsetSum >= num; subsetSum--) {
                if (existSubsetSum[subsetSum-num]) {
                    existSubsetSum[subsetSum] |= (existSubsetSum[subsetSum-num] << 1);
                }
            }
        }

        for (int subsetLen = 1; subsetLen < totalLength; subsetLen++) {
            // subsetSum / subsetLen == totalSum / totalLength
            if ((totalSum * subsetLen) % totalLength == 0) {
                int subsetSum =  totalSum * subsetLen / totalLength;
                if (existSubsetSum[subsetSum] & (1 << subsetLen))
                    return true;
            }
        }
        return false;
    }
};