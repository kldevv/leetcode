/*
Number: 303
Topic: Range Sum Query - Immutable
Date: 2021/7/12
Rate: Easy
https://leetcode.com/problems/range-sum-query-immutable/

Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).


Constraints:
* 1 <= nums.length <= 104
* -105 <= nums[i] <= 105
* 0 <= left <= right < nums.length
* At most 104 calls will be made to sumRange.

*/
class NumArray {
private:
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        this->sum.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            sum.push_back(sum.back()+nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        return sum[right+1] - sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */