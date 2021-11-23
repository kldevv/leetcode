/*
Number: 50
Topic: Pow(x, n)
Date: 2021/6/5
Rate: Medium

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Constraints:
* -100.0 < x < 100.0
* -2^31 <= n <= 2^31-1
* -104 <= xn <= 104

*/

class Solution {
public:
    double myPow(double x, int n) {
        // edge case
        if (!n)
            return 1;
        // just simply the reciprocal
        // to cope with INT_MIN cast to INT_MAX+1 and overflow, try to break the INT_MIN into INT_MIN+1 and -1
        if (n < 0)
            return 1 / (myPow(x, -(n+1)) * myPow(x, 1));
        if (n % 2)
            return x * myPow(x, n-1);
        return myPow(x*x, n/2);
    }
};