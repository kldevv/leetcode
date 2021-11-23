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
        // min-heap
        // 最後在 heap 裡留下的是最大的 k 個元素

        int n = nums.size();

        unordered_map<int, int> umap;
        for (const int& num : nums) {
            if (umap.count(num))
                umap[num]++;
            else
                umap[num] = 1;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (const auto& p : umap) {
            pq.push(make_pair(p.second, p.first));
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> out;
        for (int i = 0; i < k; i++) {
            out.push_back(pq.top().second);
            pq.pop();
        }
        return out;
    }
};