/*
Number: 1636
Topic: Sort Array by Increasing Frequency
Date: 2021/9/9
Rate: Easy
https://leetcode.com/problems/sort-array-by-increasing-frequency/

Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

Constraints:
    * 1 <= nums.length <= 100
    * -100 <= nums[i] <= 100
*/

class Solution {
private:
    struct compare {
        bool operator()(pair<int, int>& p1, pair<int, int>& p2){
            return p1.second < p2.second || (p1.second == p2.second && p1.first > p2.first);
        }
    };
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> umap;
        for (int num : nums) {
            umap[num] += 1;
        }
        vector<pair<int, int>> freqVal;
        for (pair<int, int> p : umap) {
            freqVal.push_back(p);
        }
        sort(freqVal.begin(), freqVal.end(), compare());
        
        vector<int> result;
        for (pair<int, int> p : freqVal) {
            for (int i = 0; i < p.second; i++)
                result.push_back(p.first);
        }
        return result;
    }
};