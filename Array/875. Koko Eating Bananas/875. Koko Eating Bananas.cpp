/*
Number: ˙875
Topic: Koko Eating Bananas
Date: 2021/10/19
Rate: Medium
https://leetcode.com/problems/koko-eating-bananas/

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Constraints:
    * 1 <= piles.length <= 104
    * piles.length <= h <= 109
    * 1 <= piles[i] <= 109
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxVal = *max_element(piles.begin(), piles.end());
        int minVal = 1;
        while (minVal < maxVal) {
            int k = minVal + (maxVal-minVal)/2;
            int hour = minHour(piles, k);
            if (hour <= h) {
                maxVal = k;
            } else {
                minVal = k + 1;
            }
        }
        return maxVal;
    }

    int minHour(vector<int> piles, int k) {
        int pileIdx = 0;
        int hour = 0;
        for (int pile : piles) {
            hour += (pile / k) + ((pile % k) > 0);
        }
        return hour;
    }
};