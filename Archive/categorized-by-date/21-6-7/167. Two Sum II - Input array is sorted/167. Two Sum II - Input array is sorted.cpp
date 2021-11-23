/*
Number: 167
Topic: Two Sum II - Input array is sorted
Date: 2021/6/7
Rate: Easy

Given an array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.

Return the indices of the two numbers (1-indexed) as an integer array answer of size 2, where 1 <= answer[0] < answer[1] <= numbers.length.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Constraints:
* 2 <= numbers.length <= 3 * 104
* -1000 <= numbers[i] <= 1000
* numbers is sorted in non-decreasing order.
* -1000 <= target <= 1000
* The tests are generated such that there is exactly one solution.

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size()-1, sum = 0;
        while (i < j) {
            sum = numbers[i] + numbers[j];
            if (sum == target)
                return {i+1, j+1};
            else if (sum < target)
                i++;
            else if (sum > target)
                j--;
        }
        return {0, 0};
    }
};