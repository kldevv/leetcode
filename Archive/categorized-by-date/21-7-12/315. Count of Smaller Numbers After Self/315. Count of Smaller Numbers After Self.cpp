/*
Number: 315
Topic: Count of Smaller Numbers After Self
Date: 2021/7/12
Rate: Hard
https://leetcode.com/problems/count-of-smaller-numbers-after-self/

You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Constraints:
* 1 <= nums.length <= 105
* -104 <= nums[i] <= 104

*/
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> dp;
        for (int i = 0; i < nums.size(); i++) {
            dp.push_back(make_pair(nums[i], i));
        }

        vector<int> out(nums.size(), 0);
        mergeSort(dp, 0, nums.size()-1, out);
        return out;
    }

    void mergeSort(vector<pair<int, int>>& dp, int start, int end, vector<int>& out) {
        if (start == end)
            return;

        int mid = start + (end-start)/2;
        mergeSort(dp, start, mid, out);
        mergeSort(dp, mid+1, end, out);
        merge(dp, start, mid, end, out);
    }

    void merge(vector<pair<int, int>>& dp, int start, int mid, int end, vector<int>& out) {
        vector<pair<int, int>> tempLeft(dp.begin()+start, dp.begin()+mid+1);
        vector<pair<int, int>> tempRight(dp.begin()+mid+1, dp.begin()+end+1);

        int left = 0, right = 0;
        int idx = start;

        int count = 0;
        while (left < tempLeft.size() && right < tempRight.size()) {
            while (right < tempRight.size() && left < tempLeft.size() && tempLeft[left].first > tempRight[right].first) {
                dp[idx++] = tempRight[right++];
                count += 1;
            }
            while (right < tempRight.size() && left < tempLeft.size() && tempLeft[left].first <= tempRight[right].first) {
                out[tempLeft[left].second] += count;
                dp[idx++] = tempLeft[left++];
            }
        }
        while (right < tempRight.size()) {
            dp[idx++] = tempRight[right++];
        }
        while (left < tempLeft.size()) {
            out[tempLeft[left].second] += count;
            dp[idx++] = tempLeft[left++];
        }
    }
};