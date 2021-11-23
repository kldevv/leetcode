/*
Number: 354
Topic: Russian Doll Envelopes
Date: 2021/7/11
Rate: Medium
https://leetcode.com/problems/longest-increasing-subsequence/

You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

Constraints:
* 1 <= envelopes.length <= 5000
* envelopes[i].length == 2
* 1 <= wi, hi <= 104
 
Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/

struct comparator {
    bool operator()(const vector<int>& v1, const vector<int>& v2) {
        if (v1[0] == v2[0])
            return v1[1] > v2[1];
        return v1[0] <= v2[0];
    }
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comparator());
        vector<vector<int>> out;

        for (int i = 0; i < envelopes.size(); i++) {
            vector<int> val = envelopes[i];
            int t = binarySearch(out, val[1]);
            if (t >= out.size())
                out.push_back(val);
            else
                out[t] = val;
        }
        return out.size();
    }

    int binarySearch(const vector<vector<int>>& nums, int target) {
        if (nums.empty())
            return 0;
        int left = 0, right = nums.size()-1;

        while (left <= right) {
            int mid = left + (right-left)/2;
            int val = nums[mid][1];

            if (val == target)
                return mid;
            if (val < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};