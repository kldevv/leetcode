/*
Number: 120
Topic: Triangle
Date: 2021/6/19
Rate: Medium
https://leetcode.com/problems/triangle/

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Constraints:
* 1 <= triangle.length <= 200
* triangle[0].length == 1
* triangle[i].length == triangle[i - 1].length + 1
* -10^4 <= triangle[i][j] <= 10^4


Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?


*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    	int n = triangle.size();
        vector<int> dp = triangle[n-1];

        // 從最下面那層開始做 dp
        // dp[j] 代表第 i 層，到第 j 位置從底部往上走的累積最小值是什麼
        // 所以這層 dp[j] 就是 triangle[i][j] 的值加上兩條可以通往這個位置的最小值
        // 往上走可以通往這層的就是下一層 j, j+1 的位置
        for (int i = n-2; i >= 0; i--) {
        	for (int j = 0; j <= i; j++) {
        		// 因為每個 dp[j] 只和 j, j+1 有關，所以直接覆蓋過去不會影響 dp[j+1] 的運算
        		dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
        	}
        }

       return dp[0];
    }
};