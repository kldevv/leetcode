/*
Number: 248
Topic: Strobogrammatic Number III
Date: 2021/7/19
Rate: Hard
https://leetcode.com/problems/strobogrammatic-number-iii/

Given two strings low and high that represent two integers low and high where low <= high, return the number of strobogrammatic numbers in the range [low, high].

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Constraints:
* 1 <= low.length, high.length <= 15
* low and high consist of only digits.
* low <= high
* low and high do not contain any leading zeros except for zero itself.

*/
class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        long lowNum = stol(low);
        long highNum = stol(high);
        int count = 0;
        for (int i = low.size(); i <= high.size(); i++) {
            vector<string> thisDecimal = findStrobogrammatic(i);
            for (string& s : thisDecimal) {
                long num = stol(s);
                if (lowNum <= num && num <= highNum)
                    count += 1;
            }
        }

        return count;
    }

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