/*
Number: 238
Topic: Product of Array Except Self
Date: 2021/5/22
Rate: Medium
https://leetcode.com/problems/product-of-array-except-self/

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Constraints:

* 2 <= nums.length <= 105
* -30 <= nums[i] <= 30
* The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
*/



class Solution {
public:
    // tc: O(n), sc: O(1) [不做 in-place 時不包含 extra space]
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out = {1};
        // 以 {1, 2, 3, 4, 5} 來說，答案會是自身 element 所有左邊的元素和右邊元素乘積的乘積
        // right {1, 1*1, 2*1*1, 3*2*1*1, 4*3*2*1*1}
        // left {5*4*3*2*1, 5*4*3*1, 5*4*1, 5*1, 1}
        //  {right * left}

        // 製造出 right
        for (int i = 1; i < nums.size(); i++) {
            // out[i] 為 i 元素左邊所有的乘積
            out.push_back(out[i-1] * nums[i-1]);
        }

        int right = 1;
        for (int i = nums.size()-1; i >= 0; i--) {
            // right 為 i 右邊所有的乘積
            out[i] *= right;
            right *= nums[i]; 
        }
        return out;
    }
};