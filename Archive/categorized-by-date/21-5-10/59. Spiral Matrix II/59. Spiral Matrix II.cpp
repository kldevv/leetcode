/*
Number: 59
Topic: Spiral Matrix II
Date: 2021/5/10
Rate: Medium
https://leetcode.com/problems/spiral-matrix-ii/

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Constraints:
* 1 <= n <= 20

*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> A;
        // 創造一個 n * n 都是 0 的矩陣
        for (int a = 0; a < n; a++) {
            vector<int> temp;
            for (int b = 0; b < n; b++) {
                temp.push_back(0);
            }
            A.push_back(temp);
        }

        int x = 0, y = 0, walk1 = 0, walk2 = 1;
        // 從 0 開始慢慢 increment，走 spiral path
        for (int i = 0; i < n*n; i++) {
            A[y][x] = i+1;
            // 檢查下一個 element 是否已經有值（非0）;
            // 加上 +n)%n 是因為當我們 check 到 n 或是 -1 時，我們實際想要檢查的是 0 和 n-1;
            if (A[(y+walk1+n) % n][(x+walk2+n) % n]) {
                // 交換步伐
                int temp = walk1;
                walk1 = walk2;
                walk2 = -temp;
            }
            y += walk1;
            x += walk2;
        }
        return A;
    }
};


