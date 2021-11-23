/*
Number: 374
Topic: Guess Number Higher or Lower
Date: 2021/7/11
Rate: Easy
https://leetcode.com/problems/guess-number-higher-or-lower/

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns 3 possible results:

-1: The number I picked is lower than your guess (i.e. pick < num).
1: The number I picked is higher than your guess (i.e. pick > num).
0: The number I picked is equal to your guess (i.e. pick == num).
Return the number that I picked.

Constraints:
* 1 <= n <= 231 - 1
* 1 <= pick <= n
*/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is lower than the guess number
 *                1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 0, right = n;
        while (left <= right) {
            int num = left + (right-left)/2;
            int result = guess(num);
            if (!result)
                return num;
            if (result == 1)
                left = num + 1;
            else
                right = num - 1;
        }
        return -1;
    }
};