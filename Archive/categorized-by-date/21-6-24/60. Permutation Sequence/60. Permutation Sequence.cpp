/*
Number: 60
Topic: Permutation Sequence
Date: 2021/6/24
Rate: Hard
https://leetcode.com/problems/permutation-sequence/

The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"

Given n and k, return the kth permutation sequence.

Constraints:
* 1 <= n <= 9
* 1 <= k <= n!
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact = facTable(n);
        vector<int> nums = rangeArr(n);

        // k-1 因為原本是 idx 1 based 把它轉成 idx 0 based
        return getPermutation(nums, k-1, fact);
    }

    string getPermutation(vector<int>& nums, int i, const vector<int>& fact) {
        // 長度只有一時，直接回傳
        if (nums.size() == 1)
            return to_string(nums[0]);

        // 看看這個 k 是第幾個數字開頭的
        // 譬如 3! 就是由 三個 2! 組成的，看看在哪一組，第一組 (idx=0) 開頭就是 1，第二組開頭是 2，以此類推
        int batch = i / fact[nums.size()-1];
        // 在這一組的第幾個
        int offset = i % fact[nums.size()-1];

        // 第一個數字知道了
        string ans = to_string(nums[batch]);
        nums.erase(nums.begin()+batch);

        // 接下來看看下一個數字是什麼
        return ans + getPermutation(nums, offset, fact);
    }

    vector<int> facTable(int n) {
        // 拿 factorial table
        vector<int> t;

        t.push_back(1);
        for (int i = 1; i <= n; i++) {
            t.push_back(t[i-1]*i);
        }

        return t;
    }

    vector<int> rangeArr(int n) {
        // 拿 range(1, n+1)
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        return nums;
    }

};