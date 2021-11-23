/*
Number: 244
Topic: Shortest Word Distance II
Date: 2021/7/16
Rate: Medium
https://leetcode.com/problems/shortest-word-distance-ii/

Design a data structure that will be initialized with a string array, and then it should answer queries of the shortest distance between two different strings from the array.

Implement the WordDistance class:

WordDistance(String[] wordsDict) initializes the object with the strings array wordsDict.
int shortest(String word1, String word2) returns the shortest distance between word1 and word2 in the array wordsDict.

Constraints:
* 1 <= wordsDict.length <= 3 * 104
* 1 <= wordsDict[i].length <= 10
* wordsDict[i] consists of lowercase English letters.
* word1 and word2 are in wordsDict.
* word1 != word2
* At most 5000 calls will be made to shortest
*/

class WordDistance {
private:
    unordered_map<string, vector<int>> wordPos;
public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); i++) {
            // 用 hashmap, list，記錄下每個字出現的每個位置
            wordPos[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int> pos1 = wordPos[word1];
        vector<int> pos2 = wordPos[word2];
        int i = 0, j = 0;
        int minDis = INT_MAX;

        // 因為都 sorted 了，這邊的 time complexity 可以變成 O(n+m), n = pos1.size(); m = pos2.size();
        // 只要其中有一個 position array 用完了就中止，因為接下來只會產生更大的 distance
        while (i < pos1.size() && j < pos2.size()) {
            minDis = min(minDis, abs(pos1[i]-pos2[j]));
            // 當 pos1[i] < pos2[j] 時，只有 i 前進，才有可能製造更小的 distance
            if (pos1[i] < pos2[j])
                i++;
            else
                j++;
        }
        return minDis;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */