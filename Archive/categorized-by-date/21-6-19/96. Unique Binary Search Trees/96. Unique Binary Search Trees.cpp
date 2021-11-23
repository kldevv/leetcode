/*
Number: 96
Topic: Unique Binary Search Trees
Date: 2021/6/19
Rate: Medium
https://leetcode.com/problems/unique-binary-search-trees/

Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

Constraints:
* 1 <= n <= 19

*/

class Solution {
public:
    int numTrees(int n) {
        // tc: O(n^2)

        // G[n] 代表在長度為 n 時，有幾種 unique combination
        vector<int> G(n+1, 0);
        // base case: 0 個 node 有一種組合，1 個 node 有 1 種
        G[0] = 1, G[1] = 1;

        // 計算長度為 0 - n 的 combination 數量
        for (int i = 2; i <= n; i++) {
            // 長度為 i 時的組合數量等於 1~i 做 root 可能的總合，每個 root 的組合數量又等於 G[root左邊剩下node數量] * G[root右邊剩下node數量]
            for (int j = 0; j < i; j++) {
                G[i] += G[j] * G[i-j-1];
            }
            cout << G[i] << endl;
        }

        // 或是可以用卡塔蘭數拿到 tc: O(n) 的算法
        return G[n];
    }
};