/*
Number: 31
Topic: Next Permutation
Date: 2021/5/5
Rate: Medium
https://leetcode.com/problems/next-permutation/

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

tc / O(n)
*/

// 1. 從左邊開始找，找到不是 descending order 的點 k 和 k+1 (descending order 代表無法再變更大)
// 2. 若找不到此點，代表整個 array 都是 descending order，沒有 next greater permutation，整個 reverse 就好
// 3. 找到此點(k)之後，再從此點的右方開始找比他大的第一個點 l (因為右邊已經確定是 descending order，所以第一個比 k 點大的值，就是距離 k 點最近的值)
// 4. 交換 k 和 l 的值 (利用增加下一位數製造出比原本 descending order 更大的數列，而增加下一位數的方法就是從右邊比較小位數挑一個比較大的值來掉換，不能太大，因為我們要剛好下一個大的 permutation)
// 5. 要在確保 k 點右邊的值是ascending order 這樣右邊才是以增加過後的下一位數為首最小的數列 (增加過後的下一位數右邊可以接多種數列)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = nums.size() - 2;
        int l = nums.size() - 1;
        for (k; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
        if (k < 0) {
            reverse(nums.begin(), nums.end());
        } else {
            for (l; l > k; l--){
                if (nums[l] > nums[k]) {
                    break;
                }
            }    
            swap(nums[k], nums[l]);
            reverse(nums.begin()+k+1, nums.end());        
        }
    }
};

