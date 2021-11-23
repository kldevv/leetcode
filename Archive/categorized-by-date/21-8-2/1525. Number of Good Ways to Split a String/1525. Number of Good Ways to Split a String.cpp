/*
Number: 1525
Topic: Number of Good Ways to Split a String
Date: 2021/8/2
Rate: Medium
https://leetcode.com/problems/number-of-good-ways-to-split-a-string/

You are given a string s, a split is called good if you can split s into 2 non-empty strings p and q where its concatenation is equal to s and the number of distinct letters in p and q are the same.

Return the number of good splits you can make in s.

Constraints:
* s contains only lowercase English letters.
* 1 <= s.length <= 10^5
*/

class Solution {
private:
    const int ALNUM = 26;
public:
    int numSplits(string s) {
        vector<int> left(ALNUM, 0);
        vector<int> right(ALNUM, 0);
        int uniqueLeft = 0, uniqueRight = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (++left[s[i]-'a'] == 1)
                uniqueLeft += 1;
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (--left[s[i]-'a'] == 0)
                uniqueLeft -= 1;
            if (++right[s[i]-'a'] == 1)
                uniqueRight += 1;

            count += (uniqueLeft == uniqueRight);
        }
        return count;
    }
};