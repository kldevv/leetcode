/*
Number: 1002
Topic: Find Common Characters
Date: 2021/12/12
Rate: Easy
https://leetcode.com/problems/find-common-characters/

Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

Constraints:
    * 1 <= words.length <= 100
    * 1 <= words[i].length <= 100
    * words[i] consists of lowercase English letters.
*/
#include <algorithm>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        /*
        n = words.size();
        init commonChars(26, INT_MAX);

        result = []
        for word in words:
            init counter(26, 0);
            for char in word:
                counter[idxOf(char)] = 1
            commonChar.intersect(counter);
            // Function intersect takes the min value of two arrays.
        return commonChars
        */
        int ALPNUM = 26;
        vector<int> commonChars(ALPNUM, INT_MAX);


        for (string word : words) {
            vector<int> counter(ALPNUM, 0);
            for (char c : word) {
                counter[c - 'a'] += 1;
            }
            intersect(commonChars, counter);
        }

        vector<string> results;
        for (int i = 0; i < ALPNUM; i++) {
            while (commonChars[i]) {
                char alphabet = i + 'a';
                results.push_back(string(1, alphabet));
                commonChars[i] -= 1;
            }
        }
        return results;
    }

    void intersect(vector<int>& v1, vector<int>& v2) {
        if (v1.size() != v2.size())
            return;

        int n = v1.size();
        for (int i = 0; i < n; i++) {
            v1[i] = min(v1[i], v2[i]);
        }
    }
};