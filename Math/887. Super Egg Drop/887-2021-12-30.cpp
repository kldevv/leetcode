// 2021/12/30

/*
dp[m][k] = how many floor one can get w. k eggs and m moves

recurrence:
dp[m][k] = dp[m-1][k] + dp[m-1][k-1] + 1

base:
dp[0][k] = 0
dp[m][0] = 0

dp[1][k] = 1
dp[m][1] = 1
*/

class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1, vector<int> (k+1, 0));
        int m = 1;
        while (1) {
            for (int i = 1; i <= k; i++) {
                dp[m][i] = dp[m-1][i-1] + dp[m-1][i] + 1;
            }
            if (dp[m][k] >= n)
                break;
            m++;
        }
        return m;
    }
};