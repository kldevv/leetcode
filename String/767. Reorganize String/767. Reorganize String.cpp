/*
Number: 767
Topic: Reorganize String
Date: 2021/12/7
Rate: Medium
https://leetcode.com/problems/reorganize-string/

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

Constraints:
    * 1 <= s.length <= 500
    * s consists of lowercase English letters.
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string reorganizeString(string s) {
        /*
        1. count the occurence of letters
        2. put the largest occurence number in the odd position, serving as an delimiter
        3. fill the rest of the position
        */
        vector<int> counter(26, 0);
        int maxCount = 0;
        char maxCountChar;
        for (char c : s) {
            if (++counter[c - 'a'] > maxCount) {
                maxCount = counter[c - 'a'];
                maxCountChar = c;
            }
        }

        string result(s);

        int i = 0;
        for (; i < result.size() && counter[maxCountChar - 'a'] > 0; i += 2) {
            result[i] = maxCountChar;
            counter[maxCountChar - 'a'] -= 1;
        }

        if (counter[maxCountChar - 'a'] > 0)
            return "";

        for (int k = 0; k < 26; k++) {
            while (counter[k] > 0) {
                if (i >= result.size()) {
                    i = 1;
                }
                result[i] = (char)(k + 'a');

                i += 2;
                counter[k] -= 1;
            }
        }
        return result;
    }
};