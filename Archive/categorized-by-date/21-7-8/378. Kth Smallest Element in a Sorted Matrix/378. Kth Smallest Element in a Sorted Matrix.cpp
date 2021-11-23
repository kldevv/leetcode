/*
Number: 378
Topic: Kth Smallest Element in a Sorted Matrix
Date: 2021/7/8
Rate: Medium
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Constraints:
* n == matrix.length
* n == matrix[i].length
* 1 <= n <= 300
* -109 <= matrix[i][j] <= 109
* All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
* 1 <= k <= n2
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int low = matrix[0][0];
        int high = matrix[n-1][n-1];

        while (low < high) {
            int mid = low + (high-low)/2;
            int count = 0;

            for (int i = 0; i < n; i++) {
                int j = n-1;
                while (j >= 0 && matrix[i][j] > mid)
                    j--;
                count += (j+1);
            }
            if (count < k)
                low = mid+1;
            else
                high = mid;
        }
        // 為什麼 low 一定在 matrix 裡？
        // Most binary search we can check target=mid during the search and return. But this one we cannot because the first mid we find with rank k might not exist in the matrix. Continuing the binary search finds the smallest number with rank k. For example, rank(lo-1)=k-1 and rank(lo)=k. If lo is not in the matrix, then rank(lo-1)=rank(lo)=k-1. So the smallest/first number that ranks k in the matrix must exist in the matrix.
        // 我的答案：因為 range(mid) 的時候不足 k 個元素，所以 range(mid+1) 的時候如果有 k 個元素以上，不就代表 mid+1 就是那第 k 個數字嗎！
        // 而如果這時候還沒 converge 也沒關係，因為 range((mid+1 + high)/2) 也會大於 k 個元素，這時候 low 不會變，而是 high 會慢慢縮過來。
        return low;
    }
};