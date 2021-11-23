/*
Number: 347
Topic: Top K Frequent Elements
Date: 2021/7/3
Rate: Medium
https://leetcode.com/problems/top-k-frequent-elements/

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Constraints:
* 1 <= nums.length <= 105
* k is in the range [1, the number of unique elements in the array].
* It is guaranteed that the answer is unique.
 
Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // bucket sort solution
        // O(n)
        // 先拿到每一個元素的頻率
        // 再把頻率當作 idx 放進 frequency vector 裡
        // 最後從最後面的 frequency 開始累積輸出

        int n = nums.size();

        unordered_map<int, int> umap;
        for (const int& num : nums) {
            if (umap.count(num))
                umap[num]++;
            else
                umap[num] = 1;
        } 

        vector<vector<int>> frequency(n, vector<int>(0, 1));
        for (const auto& p : umap) {
            frequency[p.second-1].push_back(p.first);
        }

        vector<int> out;
        for (int i = n-1; i >= 0; i--) {
            if (!frequency[i].empty()) {
                move(frequency[i].begin(), frequency[i].end(), back_inserter(out));
                if (out.size() == k)
                    break;
            }
        }
        return out;
    }
};