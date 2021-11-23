/*
Number: 1481
Topic: Least Number of Unique Integers after K Removals
Date: 2021/9/25
Rate: Medium
https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

Constraints:
    * 1 <= arr.length <= 10^5
    * 1 <= arr[i] <= 10^9
    * 0 <= k <= arr.length
*/

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> counter;
        for (int& num : arr) {
            counter[num] += 1;
        }

        vector<int> freqCounter(arr.size()+1, 0);
        for (auto p : counter) {
            freqCounter[p.second] += 1;

        }

        int unique = counter.size();
        for (int i = 1; i < freqCounter.size(); i++) {
            if (k - i * freqCounter[i] >= 0) {
                k -= i * freqCounter[i];
                unique -= freqCounter[i];
            } else {
                return unique - (k / i);
            }
        }
        return unique;
    }
};