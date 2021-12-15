/*
Number: 39
Topic: Combination Sum
Date: 2021/12/5
Rate: Medium
https://leetcode.com/problems/combination-sum/

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Constraints:
    * 1 <= candidates.length <= 30
    * 1 <= candidates[i] <= 200
    * All elements of candidates are distinct.
    * 1 <= target <= 500
*/

#include <vector>

using namespace std;

class Solution {
   private:
    vector<vector<int>> results;
    vector<int> partial;

   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        /*
        Base Case:
            if (target == 0)
                results.push()
                return;
            if (target < 0)
                return;

        take some value from candidates;
            -> recursive(target-value);

        Example:
        [2, 8], k = 10
            -> take 2 => k = 8
                -> take 2 => k = 6 (2, 8)
                    -> ....
                -> take 8 => k = 0

            -> take 8 => k = 2
                -> take 2 => k = 0 (8, 2) Duplicate!

        Create Direction => only from small to large
        */
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, 0, target);
        return results;
    }

    void combinationSum(vector<int>& candidates, int start, int target) {
        if (target == 0) {
            results.push_back(partial);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            partial.push_back(candidates[i]);
            combinationSum(candidates, i, target - candidates[i]);
            partial.pop_back();
        }
    }
};