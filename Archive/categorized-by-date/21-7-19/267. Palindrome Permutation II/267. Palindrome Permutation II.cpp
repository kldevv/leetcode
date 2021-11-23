/*
Number: 267
Topic: Palindrome Permutation II
Date: 2021/7/19
Rate: Medium
https://leetcode.com/problems/palindrome-permutation-ii/

Given a string s, return all the palindromic permutations (without duplicates) of it.

You may return the answer in any order. If s has no palindromic permutation, return an empty list.

Constraints:
* 1 <= s.length <= 16
* s consists of only lowercase English letters.
*/

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<int> dict(256, 0);
        int n = s.size();
        for (const char& c : s) {
            dict[c] += 1;
        }

        int uniqueCount = 0;
        string uniqueChar;
        string prefix;

        for (int i = 0; i < dict.size(); i++) {
            if (dict[i]%2) {
                uniqueCount += 1;
                uniqueChar = string(1, (char)i);
                dict[i] -= 1;
            }
            if (dict[i]) {
                prefix += string(dict[i]/2, (char)i);
                dict[i] = 0;
            }

            if (uniqueCount > 1)
                return {};
        }

        vector<string> out = stringPermutation(prefix);
        for (int i = 0; i < out.size(); i++) {
            string prefix = out[i];
            string suffix(prefix);
            reverse(suffix.begin(), suffix.end());
            out[i] = prefix + uniqueChar + suffix;
        }

        return out;
    }


    vector<string> stringPermutation(string s) {
        vector<string> out;
        string t(s);
        do {
            next_permutation(s.begin(), s.end());
            out.push_back(s);
        } while (s != t);

        return out;
    }
};