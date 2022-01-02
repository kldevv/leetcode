// 2021/12/30

/*
n < (n/2)^2

- Any value larger than 3 should be broken down to factors
2 > (1 * 1)
3 > (1 * 2)
4 == (2 * 2)
5 < (3 * 2)

- 2 vs 3
4 => 2 * 2 = 4
4 => 1 * 3 = 3

6 => 2 * 2 * 2 = 8
6 => 3 * 3 = 9
*/
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n < 3)
            return 1;
        if (n == 3)
            return 2;

        int result = pow(3, n/3);

        if (n % 3 == 1)
            return result / 3 * 4;
        else
            return result * max((n % 3), 1);
    }
};