/*
Number: 221
Topic: Maximal Square
Date: 2021/6/23
Rate: Medium
https://leetcode.com/problems/maximal-square/

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Constraints:
* m == matrix.length
* n == matrix[i].length
* 1 <= m, n <= 300
* matrix[i][j] is '0' or '1'.

*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // see post: https://leetcode.com/problems/maximal-square/discuss/61803/C%2B%2B-space-optimized-DP
        int m = matrix.size(), n = (m) ? matrix[0].size() : 0;
        vector<int> pre(n, 0);
        vector<int> cur(n, 0);

        int maxSize = 0;

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (!i || !j || matrix[j][i] == '0') {
                    // 如果 i == 0 或 j == 0 或是 matrix[j][i] == 0 那麼到這格為止的最大長度就只有可能是當前格子的值
                    cur[i] = matrix[j][i] - '0';
                } else {
                    // 如果不在邊界上，而且 matrix[j][i] == 1，那我們就可以檢查右邊，上面，上右四格，到目前為止最大的長度是什麼，取最小的那個，因為我們要做一個正方形，把他再 + 1 因為加上這格就等於整個邊長 + 1 了
                    cur[i] = min(cur[i-1], min(pre[i-1], pre[i])) + 1;
                }
                maxSize = max(maxSize, cur[i]);
            }
            // 我們只在意目前這個 row 與上面那個 row，所以用兩個 vector 就好
            fill(pre.begin(), pre.end(), 0);
            swap(pre, cur);
        }
        return maxSize * maxSize;
    }
};