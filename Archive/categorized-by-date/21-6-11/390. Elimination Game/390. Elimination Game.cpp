/*
Number: 390
Topic: Elimination Game
Date: 2021/6/11
Rate: Medium
https://leetcode.com/problems/elimination-game/

You have a list arr of all integers in the range [1, n] sorted in a strictly increasing order. Apply the following algorithm on arr:

* Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
* Repeat the previous step again, but this time from right to left, remove the rightmost number and every other number from the remaining numbers.
* Keep repeating the steps again, alternating left to right and right to left, until a single number remains.

Given the integer n, return the last number that remains in arr.

Constraints:
* 1 <= n <= 109

*/

class Solution {
public:
    int lastRemaining(int n) {
        return eleminateFromLeft(n);
    }

    // 從左邊消除，每個 odd position 都會被消除，剩下 2 4 6 8 這種 even 的數 也就是 2 * (1 2 3 4)
    int eleminateFromLeft(int n) {
        if (n == 1)
            return 1;
        return 2 * eleminateFromRight(n/2);
    }
    // 123
    // 2 = 2*1
    // 12
    // 2 = 2*1

    // 從右邊消除，如果是從偶數開始消除，就每個偶數都會消除，只留下基數位 1 3 5 7 也就是 2 * (1 2 3 4) -1
    // 如果從基數開始消除，每個基數都會消除，只留下偶數位
    int eleminateFromRight(int n) { 
        if (n == 1)
            return 1;
        if (n % 2 == 1)
            return 2 * eleminateFromLeft(n/2);
        return 2 * eleminateFromLeft(n/2) - 1;

    }
    // 1234
    // 13 = 2*1-1, 2*2-1
    // 123 
    // 2 = 2*1
};