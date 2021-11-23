/*
Number: 397
Topic: Integer Replacement
Date: 2021/6/12
Rate: Medium
https://leetcode.com/problems/integer-replacement/

Given a positive integer n, you can apply one of the following operations:

If n is even, replace n with n / 2.
If n is odd, replace n with either n + 1 or n - 1.
Return the minimum number of operations needed for n to become 1.

Constraints:
* 1 <= n <= 2^31 - 1

*/

class Solution {
public:
    // tc: O(logN)
    int integerReplacement(int n) {
        // INT_MAX = 2^31-1; log_2^(INT_MAX+1) = 32
        if (n == INT_MAX)
            return 32;

        int step = 0;
        while (n != 1) {
            // 偶數的話就直接除二
            if (n % 2 == 0) {
                n /= 2;
            // 基數的話就要考慮 +1 或是 -1，目標是每次除以二後都是偶數，因為我們要盡量用除的
            } else {
                if (n != 3 && (n+1) % 4 == 0)
                    n += 1;
                else 
                    n -= 1;  
            }
            step += 1;
        }
        return step;
    }
    // let n = 2k+1
    // then: (1) n+1 = 2k+2, (2) n-1 = 2k

    // (1) => (n+1)/2 = k+1; 此時已經用了兩步
    // (2) => (n-1)/2 = k; 此時已經用了兩步
    // 若 (n+1) % 4 == 0，k+1 是偶數，k 是基數

    // 此時 let k == 2h+1 ， 且 k != 1
    // 若 h 是奇數（或是 1）：
    // (1) => (k+1)/2 = h+1 此時已經用了三步，且可以馬上在除一次二
    // (2) => (k+1)/2 = h+1 此時已經用了四步，才能再除一次二
    // 若 h 是偶數：
    // (1) => (k+1)/2 = h+1 此時已經用了三步，再做一次運算才能再除以二，所以是四步
    // (2) => (k-1)/2 = h 此時已經用了四步，才能再除一次二
    // 所以當 (n+1) % 4 == 0 時，用 +1 的準沒錯，只會比 -1 好或相同，除了三這個例外
};