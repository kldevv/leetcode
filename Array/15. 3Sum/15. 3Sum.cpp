/*
Number: 15
Topic: 3Sum
Date: 2021/12/5
Rate: Medium
https://leetcode.com/problems/3sum/

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Constraints:
    * 0 <= nums.length <= 3000
    * -105 <= nums[i] <= 105
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
        sorted(num)

        for firstIdx in num:
            SKIP REPEAT:
                while (firstIdx != 0 && num[firstIdx-1] == num[firstIdx])
                    firstIdx += 1

            secondIdx = firstIdx + 1
            thirdIdx = num.size()-1
            while (sec. < thi.):
                SKIP REPEAT:
                    while (sec. != fir.+1 && num[sec.-1] == num[sec])
                        sec. += 1

                if (nums[* sec. + thi. + fir.] == target)
                    results.add()
                    sec. ++
                .. < target:
                    sec. ++
                else:
                    thir --

        Example:
            [1, 1, 1, 1], 3
            (1, 1, 1)
        */
        int first = 0;
        int second;
        int third;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> results;

        for (; first < n; first++) {
            while (first < n && first != 0 && nums[first - 1] == nums[first])
                first += 1;
            second = first + 1;
            third = n - 1;
            while (second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                if (sum == 0) {
                    results.push_back({nums[first], nums[second], nums[third]});
                    second += 1;
                } else if (sum < 0) {
                    second += 1;
                } else {  // sum > 0
                    third -= 1;
                }
                while (second < n && second != first + 1 && nums[second - 1] == nums[second])
                    second += 1;
            }
        }
        return results;
    }
};