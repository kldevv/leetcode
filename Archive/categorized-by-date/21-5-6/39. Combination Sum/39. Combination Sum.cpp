/*
Number: 39
Topic: Combination Sum
Date: 2021/5/6
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


tc / O(n*m) where n is the number of elements in the candidates and m is the target.
furthur explanation:
https://leetcode.com/problems/combination-sum/discuss/742449/Explanation-of-Time-Complexity
*/


// 經典 backtracking problem
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> out;
        vector<int> temp;
        combinationBT(candidates, target, 0, out, temp);
        return out;
    }
private:
    void combinationBT(vector<int>& candidates, int target, int start, vector<vector<int>>& out, vector<int>& prevComb){
        for (int i = start; i < candidates.size(); i++){
            if (target < candidates[i]) break;
            if (target == candidates[i]){
                prevComb.push_back(candidates[i]);
                out.push_back(prevComb);
                prevComb.pop_back();
                break;
            }

            prevComb.push_back(candidates[i]);
            combinationBT(candidates, target-candidates[i], i, out, prevComb);
            prevComb.pop_back();
        }
    }
};