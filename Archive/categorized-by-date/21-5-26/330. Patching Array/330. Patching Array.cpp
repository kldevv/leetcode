/*
Number: 330
Topic: Patching Array
Date: 2021/5/26
Rate: Hard
https://leetcode.com/problems/patching-array/

Given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] inclusive can be formed by the sum of some elements in the array.

Return the minimum number of patches required.

Constraints:

* 1 <= nums.length <= 1000
* 1 <= nums[i] <= 104
* nums is sorted in ascending order.
* 1 <= n <= 231 - 1

*/

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1, add_num = 0, idx = 0;
        while (miss <= n) {
            if (idx < nums.size() && nums[idx] <= miss) {
                // 當 nums[idx] <= miss 時，因為我們可以用 nums[:idx] 的元素拼出 [1, miss) 的值
                // 所以我們可以拼出 [1, miss+nums[idx]) 的值，只要把 nums[idx] 放進 combination 裡就可以，剩下的用 nums[:idx] 拼成
                miss += nums[idx++];
            } else {
                // 但是當 nums[idx] > miss 時，我們首先就無法拼出 miss 了
                // 所以要加入 miss ， 代表 add_num 要＋1
                // 同理如上，加入 miss 後，可以組成 [1, miss+miss) 的值了
                miss += miss;
                add_num++;
            }
        }
        return add_num;
    }
};