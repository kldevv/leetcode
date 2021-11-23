/*
Number: 47
Topic: Permutations II
Date: 2021/6/23
Rate: Medium
https://leetcode.com/problems/permutations-ii/

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.


Constraints:
* 1 <= nums.length <= 8
* -10 <= nums[i] <= 10

*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> out;
        permuteUnique(nums, 0, out);
        return out;
    }

    void permuteUnique(vector<int> nums, int i, vector<vector<int>>& out) {
        if (i == nums.size()) {
            out.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for (int j = i; j < nums.size(); j++){
            // 不要再拿重複的地方做頭
            if (st.count(nums[j])
                continue;
            st.insert(nums[j]);
            swap(nums[i], nums[j]);
            permuteUnique(nums, i+1, out);
            swap(nums[i], nums[j]);
        }
    }
};