/*
Number: 564
Topic: Find the Closest Palindrome
Date: 2021/8/21
Rate: Hard
https://leetcode.com/problems/find-the-closest-palindrome/

Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.

The closest is defined as the absolute difference minimized between two integers.

Constraints:
* 1 <= n.length <= 18
* n consists of only digits.
* n does not have leading zeros.
* n is representing an integer in the range [1, 1018 - 1].
*/

class Solution {
public:
    string nearestPalindromic(string n) {
        int l = n.size();
        set<long> candidates;
        // biggest, one more digit, 10...01
        candidates.insert(long(pow(10, l)) + 1);
        // smallest, one less digit, 9...9 or 0
        candidates.insert(long(pow(10, l - 1)) - 1);
        // the closest must be in middle digit +1, 0, -1, then flip left to right
        long prefix = stol(n.substr(0, (l + 1) / 2));
        for ( long i = -1; i <= 1; ++i ) {
            string p = to_string(prefix + i);
            string pp = p + string(p.rbegin() + (l & 1), p.rend());
            candidates.insert(stol(pp));
        }
        long num = stol(n), minDiff = LONG_MAX, diff, minVal;
        candidates.erase(num);
        for (long val : candidates) {
            diff = abs(val - num);
            if (diff < minDiff) {
                minDiff = diff;
                minVal = val;s
            } else if (diff == minDiff) {
                minVal = min(minVal, val);
            }
        }
        return to_string(minVal);
    }
};