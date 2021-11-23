/*
Number: 348
Topic: Shuffle an Array
Date: 2021/6/26
Rate: Medium
https://leetcode.com/problems/shuffle-an-array/

Given an integer array nums, design an algorithm to randomly shuffle the array.

Implement the Solution class:

* Solution(int[] nums) Initializes the object with the integer array nums.
* int[] reset() Resets the array to its original configuration and returns it.
* int[] shuffle() Returns a random shuffling of the array.

Constraints:
* 1 <= nums.length <= 200
* -10^6 <= nums[i] <= 10^6
* All the elements of nums are unique.
* At most 5 * 104 calls will be made to reset and shuffle.

*/

class Solution {
public:
    vector<int> ori;
    Solution(vector<int>& nums) {
        this->ori = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return ori;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffled(ori);
        for (int i = 0; i < shuffled.size(); i++) {
            int j = rand() % shuffled.size();
            swap(shuffled[i], shuffled[j]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */