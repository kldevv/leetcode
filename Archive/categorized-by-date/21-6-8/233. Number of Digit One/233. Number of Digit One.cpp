/*
Number: 233
Topic: Number of Digit One
Date: 2021/6/7
Rate: Hard

Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

Constraints:
* 0 <= n <= 2 * 10^9
*/
class Solution {
public:
    int countDigitOne(int n) {
        int ones = 0;
        for (long m = 1; m <= n; m *= 10)
            // 每一個位數拆開來看
            // e.g. 2304
            // 在 1 位數
            // (2304 + 8) / 10 = 出現過 231 個 1，[0, 2301] 有 231 個 1 的循環在 1 位數
            // 在 10 位數
            // (230 + 8) / 10 * 10 = 出現過 23 個 10， [0, 230] 有 10 個 1 的循環在 10 位數。而因為是 10 位數的巡還，每次 1Ｘ 出現時就是出現 10 次（後面 1 位數的循環會出現十次）。
            ones += (n/m + 8) / 10 * m + (n/m % 10 == 1) * (n%m + 1);
            // +8 是為了確保最後一個循環是否出現，譬如 1118，代表在十位數時，最後一個循環沒有 10 個，只有 8 個，因此 110+(8+1)， (8+1) 就是 [0, 8] 了
            // 只有 n/m % 10 >= 2 時，才會跑完一個完整的循環
        return ones;
    }
};