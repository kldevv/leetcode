/*
Number: 1395
Topic: Count Number of Teams_O(n^2)-solution
Date: 2021/11/1
Rate: Medium
https://leetcode.com/problems/count-number-of-teams/

There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:
* Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
* A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).

Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

Constraints:
    * n == rating.length
    * 3 <= n <= 1000
    * 1 <= rating[i] <= 105
    * All the integers in rating are unique.
*/

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();

        int result = 0;
        for (int center = 0; center < n; center++) {
            int leftSmallCount = 0;
            int leftBigCount = 0;
            int rightSmallCount = 0;
            int rightBigCount = 0;            
            for (int guards = 0; guards < n; guards++) {
                if (guards < center) {
                    if (rating[guards] < rating[center])
                        leftSmallCount += 1;
                    if (rating[guards] > rating[center])
                        leftBigCount += 1;
                }
                if (guards > center) {
                    if (rating[guards] < rating[center])
                        rightSmallCount += 1;
                    if (rating[guards] > rating[center])
                        rightBigCount += 1;
                }
            }
            result += (leftSmallCount*rightBigCount) + (leftBigCount*rightSmallCount);
        }
        return result;
    }
};