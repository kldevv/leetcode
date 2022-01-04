// 2022/01/03

// profit[k][1] = max(profit[k][1], profit[k][0] - prices[i])
// profit[k][0] = max(profit[k][0], profit[k-1][1] + prices[i])
// profit[0][0] = 0
// profit[0][1] = -prices[0];
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> profit(k+1, vector<int>(2, INT_MIN));
        profit[0][0] = 0;

        for (int price : prices) {
            for (int i = 1; i <= k; i++) {
                profit[i][1] = max(profit[i][1], profit[i-1][0] - price);
                profit[i][0] = max(profit[i][0], profit[i][1] + price);
            }
        }
        return max(0, profit[k][0]);
    }
};