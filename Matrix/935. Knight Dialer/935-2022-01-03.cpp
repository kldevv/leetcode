// 2022/01/03
#include <vector>

using namespace std;

class Solution {
private:
    int BASE = 1e9 + 7;
    vector<vector<int>> matrix
    {
        {4, 6},
        {6, 8},
        {7, 9}, 
        {4, 8}, 
        {3, 9, 0}, 
        {}, 
        {1, 7, 0}, 
        {2, 6}, 
        {1, 3}, 
        {4, 2}
    };

public:
    int knightDialer(int n) {
        if (n == 0)
            return 0;

        vector<int> count(10, 1);
        n -= 1;

        for (; n > 0; n--) {
            vector<int> trans(10, 0);   
            for (int i = 0; i < 10; i++) {
                for (int next : matrix[i]) {
                    trans[next] = (trans[next] + count[i]) % BASE;
                }
            }
            swap(count, trans);
        }

        int result = 0;
        for (int num : count) {
            result += num;
            result %= BASE;
        }
        return result;
    }
};
