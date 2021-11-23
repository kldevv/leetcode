class Solution {
public:
    // brute force in C++
    // time complexity O(n^2)
    // space complexity O(1)
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size() - 1; i++){
            for(int n = i + 1; n < nums.size(); n++ ){
                if((nums[i] + nums[n]) == target){
                    return vector<int>{i, n};
                }
            }
        }
        return vector<int>{};
    }
};