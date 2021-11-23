/*
Number: 243
Topic: Shortest Word Distance
Date: 2021/7/16
Rate: Easy
https://leetcode.com/problems/shortest-word-distance/

Given an array of strings wordsDict and two different strings that already exist in the array word1 and word2, return the shortest distance between these two words in the list.

Constraints:
* 1 <= wordsDict.length <= 3 * 104
* 1 <= wordsDict[i].length <= 10
* wordsDict[i] consists of lowercase English letters.
* word1 and word2 are in wordsDict.
* word1 != word2
*/

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int pos1 = -1;
        int pos2 = -1;
        int minDis = INT_MAX;

        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1)
                pos1 = i;
            if (wordsDict[i] == word2)
                pos2 = i;
            if (pos1 != -1 && pos2 != -1)
                minDis = min(minDis, abs(pos2-pos1));
        }
        return minDis;
    }
};