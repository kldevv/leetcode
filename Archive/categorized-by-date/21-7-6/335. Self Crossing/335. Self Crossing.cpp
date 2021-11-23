/*
Number: 335
Topic: Self Crossing
Date: 2021/7/6
Rate: Hard
https://leetcode.com/problems/self-crossing/

You are given an array of integers distance.

You start at point (0,0) on an X-Y plane and you move distance[0] meters to the north, then distance[1] meters to the west, distance[2] meters to the south, distance[3] meters to the east, and so on. In other words, after each move, your direction changes counter-clockwise.

Return true if your path crosses itself, and false if it does not.

Constraints:
* 1 <= distance.length <= 10^5
* 1 <= distance[i] <= 10^5

*/

class Solution {
public:
    // see post: https://leetcode.com/problems/self-crossing/discuss/79141/Another-python...
    /*
            Case 1                  Case 2                  Case 2
                c                       d                       e
       +----------------+      +----------------+      +----------------+
       |                |      |                |      |                |
       |                |      |                |      |                |
     b |                | d  c |                | e  d |                | f
       |                |      |                |      |                |    a
       +--------------->|      |                |      |                | <----+
                a       |      |                ^ a    |                |      | b
                               |                |      |                       |
                               +----------------+      +-----------------------+
    */
    bool isSelfCrossing(vector<int>& distance) {
        int b = 0, c = 0, d = 0, e = 0, f = 0;
        for (const int& a : distance) {
            if (d >= b && b > 0) {
                if (c <= a)
                    return true;
                if (c-e <= a && c-e > 0 && d-f <= b)
                    return true;
            }
            f = e, e = d, d = c, c = b, b = a;
        }

        return false;
    }
};