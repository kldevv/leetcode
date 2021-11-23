/*
Number: 247
Topic: Strobogrammatic Number II
Date: 2021/7/19
Rate: Medium
https://leetcode.com/problems/strobogrammatic-number-ii/


Given an integer n, return all the strobogrammatic numbers that are of length n. You may return the answer in any order.

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Constraints:
* 1 <= n <= 14

*/
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<pair<string, string>> candidates = {{"0", "0"}, {"1", "1"}, {"8", "8"}, {"6", "9"}, {"9", "6"}};
        vector<string> out;

        for (const pair<string, string>& prefixSuffix : candidates) {
            if (n%2) {
                if (prefixSuffix.first == "9" || prefixSuffix.first == "6")
                    continue;
                findStrobogrammatic(n, candidates, prefixSuffix.first, out);
            }
            else {
                if (prefixSuffix.first == "0" && n == 2)
                    continue;
                findStrobogrammatic(n, candidates, prefixSuffix.first+prefixSuffix.second, out);
            }
        }
        return out;
    }

    void findStrobogrammatic(int n, const vector<pair<string, string>>& candidates, string num, vector<string>& out) {
        if (num.size() == n) {
            out.push_back(num);
            return;
        }

        for (const pair<string, string>& prefixSuffix : candidates) {
            if (num.size() == n-2 && prefixSuffix.first == "0")
                continue;
            string newNum = prefixSuffix.first + num + prefixSuffix.second;

            findStrobogrammatic(n, candidates, newNum, out);
        }
    }
};