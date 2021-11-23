/*
Number: 245
Topic: Shortest Word Distance III
Date: 2021/7/16
Rate: Medium
https://leetcode.com/problems/shortest-word-distance-iii/

Given an array of strings wordsDict and two strings that already exist in the array word1 and word2, return the shortest distance between these two words in the list.

Note that word1 and word2 may be the same. It is guaranteed that they represent two individual words in the list.

Constraints:
* 1 <= wordsDict.length <= 105
* 1 <= wordsDict[i].length <= 10
* wordsDict[i] consists of lowercase English letters.
* word1 and word2 are in wordsDict.
*/

class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int pos1 = -1;
        int pos2 = -1;
        int minDis = INT_MAX;

        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1)
                pos1 = i;
            if (wordsDict[i] == word2) {
                // 如果 word1 == word2 的情況，這時候讓 pos1 變成上一個出現的 pos2
                if (word1 == word2)
                    pos1 = pos2;
                pos2 = i;
            }
            if (pos1 != -1 && pos2 != -1)
                minDis = min(minDis, abs(pos1-pos2));
        }
        return minDis;
    }
};