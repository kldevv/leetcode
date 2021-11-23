/*
Number: 1
Topic: Two Sum
Date: 2021/9/30
Rate: Easy
https://leetcode.com/problems/two-sum/

Constraints:
    * 2 <= nums.length <= 104
    * -109 <= nums[i] <= 109
    * -109 <= target <= 109
    * Only one valid answer exists.
 
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> offset;
        for (int i = 0; i < nums.size(); i++) {
            if (offset.count(target - nums[i])) {
                return {i, offset[target - nums[i]]};
            }
            offset[nums[i]] = i;
        }
        return -1;
    }
};