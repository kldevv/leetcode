/*
Number: 373
Topic: Find K Pairs with Smallest Sums
Date: 2021/7/3
Rate: Medium
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

Constraints:
* 1 <= nums1.length, nums2.length <= 104
* -109 <= nums1[i], nums2[i] <= 109
* nums1 and nums2 both are sorted in ascending order.
* 1 <= k <= 1000

*/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        addValue(0, 0, pq, nums1, nums2);
        vector<vector<int>> out;

        // see post: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/84550/Slow-1-liner-to-Fast-solutions
        // 最簡單的就是 brute force 所有組合，放進 minHeap 裡面選最小的 K 的
        // 或是我們也可以每次都選出下一個最小可能的 candidate，再放進 heap 裡面做選擇
        
        // tc: O(klogM) 最多只要找 K 個元素，而每次都要在 Heap 裡面存取東西，根據 space complexity，拿取東西需要 O(logM)
        // sc: O(logM) where M 是 y 的長度，因為每次都是拿一放一，只有在 x==0 時才會拿一放二，最糟的情況就是一直拿一放二，直到 y 到底，也就是 y 多長 m 就有多少
        for (int i = 0; i < k && !pq.empty(); i++) {
            pair<int, pair<int, int>> smallest = pq.top();
            pq.pop();
            int x = smallest.second.first;
            int y = smallest.second.second;
            out.push_back({nums1[x], nums2[y]});
            // 每次都會放右邊一個
            addValue(x+1, y, pq, nums1, nums2);
            // 只有在 x==0 時才會往下找
            if (x == 0)
                addValue(x, y+1, pq, nums1, nums2);
        }
        return out;
    }
private:
    void addValue(int x, int y, priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> & pq, const vector<int>& nums1, const vector<int>& nums2) {
        if (x < nums1.size() && y < nums2.size())
            pq.push(make_pair(nums1[x]+nums2[y], make_pair(x, y)));
    }
};