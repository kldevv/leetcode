/*
Number: 204
Topic: Count Primes
Date: 2021/6/5
Rate: Easy

Count the number of prime numbers less than a non-negative number, n.

Constraints:
0 <= n <= 5 * 10^6

*/

class Solution {
public:
    int countPrimes(int n) {
        if (!n) 
            return 0;

        // Sieve of Eratosthenes
        // tc O(nloglogN)
        vector<bool> prime(n, true);
        prime[0] = false, prime[1] = false;

        // only goes to sqrt(n) because the numbers after sqrt(n) have already been handled
        for (int i = 0; i < sqrt(n); i++) {
            if (prime[i]) {
                // 從 i*i 開始搜尋，因為 [0, i-1]*i 已經被在處理 [0, i-1] 時處理過了
                for (int j = i*i; j < n; j += i) {
                    prime[j] = false;
                }    
            }    
        }
        return count(prime.begin(), prime.end(), true);
    }
};