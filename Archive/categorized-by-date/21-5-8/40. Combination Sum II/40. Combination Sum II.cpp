/*
Number: 40
Topic: Combination Sum II
Date: 2021/5/8
Rate: Medium
https://leetcode.com/problems/combination-sum-ii/

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Constraints:
* 1 <= candidates.length <= 100
* 1 <= candidates[i] <= 50
* 1 <= target <= 30


tc / O(n*m) where n is the number of elements in the candidates and m is the target.
furthur explanation:
https://leetcode.com/problems/combination-sum/discuss/742449/Explanation-of-Time-Complexity
*/


// 經典 backtracking problem
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> out;
        vector<int> temp;
        combinationBT(candidates, target, 0, out, temp);
        return out;
    }
private:
    void combinationBT(vector<int>& candidates, int target, int start, vector<vector<int>>& out, vector<int>& prevComb){
        for (int i = start; i < candidates.size(); i++){
            if (target < candidates[i]) 
                break;
            // duplicate check
            if (i && (candidates[i] == candidates[i-1]) && (i > start))
                continue;
            if (target == candidates[i]){
                prevComb.push_back(candidates[i]);
                out.push_back(prevComb);
                prevComb.pop_back();
                break;
            }
            prevComb.push_back(candidates[i]);
            combinationBT(candidates, target-candidates[i], i+1, out, prevComb);
            prevComb.pop_back();
        }
    }
};