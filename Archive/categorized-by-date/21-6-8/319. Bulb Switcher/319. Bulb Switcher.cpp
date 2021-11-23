/*
Number: 319
Topic: Bulb Switcher
Date: 2021/6/7
Rate: Medium

There are n bulbs that are initially off. You first turn on all the bulbs, then you turn off every second bulb.

On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb.

Return the number of bulbs that are on after n rounds.

Constraints:
* 0 <= n <= 2 * 10^9
*/
class Solution {
public:
    // tc O(1)
    int bulbSwitch(int n) {
        // consider all N bulb to be turned-off in the initial states (i = 0)
        // the i-th bulb will be toggle in their factor turns (e.g. 6 = 1, 2, 3, 6)
        // if i has even factors, the eventual states will be off.
        // if i has odd factors, the eventual states will be on.
        // i have odd factors if it is a perfect square number.

        // the question thus becomes, to find the number of perfect square numebr no more than N.
        // find the number of perfect square numebr no more than N, we just take the maximum perfect number no more than N.
        // and take its square root. e.g. f(1000) = 31, because 31^31 = 961, the number in [1, 31] is all perfect square number no more than N
        // so we will have 31 perfect square numbers no more than 1000

        // the complexity of computing a square root depends on the implementation and CPU 
        return sqrt(n);
    }
};