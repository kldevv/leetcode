/*
Number: 126
Topic: Word Ladder II
Date: 2021/12/4
Rate: Hard
https://leetcode.com/problems/word-ladder-ii/

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
    * Every adjacent pair of words differs by a single letter.
    * Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    * sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

Constraints:
    * 1 <= beginWord.length <= 5
    * endWord.length == beginWord.length
    * 1 <= wordList.length <= 1000
    * wordList[i].length == beginWord.length
    * beginWord, endWord, and wordList[i] consist of lowercase English letters.
    * beginWord != endWord
    * All the words in wordList are unique.
*/

#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        /*
        Strict Breath First Search

        For each root:
            If root  == endWord:
                results.append(history)
            If results.size():
                continue

            GetTransform(root)
            For each transform of root:
                If root in validWords:
                    validWords.erase(root)
                    Turn transform into root => put to next round

        */
        unordered_set<string> validWords(wordList.begin(), wordList.end());
        validWords.erase(beginWord);

        queue<string> transforms;
        transforms.push(beginWord);

        unordered_map<string, vector<string>> relations;

        while (transforms.size()) {
            int n = transforms.size();
            unordered_set<string> visited;

            if (validWords.count(endWord) == 0)
                break;

            for (int i = 0; i < n; i++) {
                string root = transforms.front();
                transforms.pop();

                vector<string> transformOfRoot;
                getTransforms(root, transformOfRoot, validWords);

                for (string newTransform : transformOfRoot) {
                    if (validWords.count(newTransform)) {
                        relations[root].push_back(newTransform);
                        visited.insert(newTransform);
                    }
                }
            }
            for (string v : visited) {
                transforms.push(v);
                validWords.erase(v);
            }
        }

        vector<vector<string>> results;
        vector<string> result = {beginWord};

        getHistory(beginWord, endWord, relations, results, result);
        return results;
    }

    void getHistory(string& root, string& dest, unordered_map<string, vector<string>>& relations, vector<vector<string>>& results, vector<string>& result) {
        if (root == dest) {
            results.push_back(result);
            return;
        }

        for (string newRoot : relations[root]) {
            result.push_back(newRoot);
            getHistory(newRoot, dest, relations, results, result);
            result.pop_back();
        }
    }

    void getTransforms(string root, vector<string>& results, unordered_set<string>& validWords) {
        for (int i = 0; i < root.size(); i++) {
            char oldChar = root[i];
            for (char c = 'a'; c <= 'z'; c++) {
                root[i] = c;
                if (c != oldChar && validWords.count(root))
                    results.push_back(root);
            }
            root[i] = oldChar;
        }
    }
};