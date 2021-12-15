/*
Number: 127
Topic: Word Ladder
Date: 2021/12/3
Rate: Hard
https://leetcode.com/problems/word-ladder/

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
    * Every adjacent pair of words differs by a single letter.
    * Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    * sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Constraints:
    * 1 <= beginWord.length <= 10
    * endWord.length == beginWord.length
    * 1 <= wordList.length <= 5000
    * wordList[i].length == beginWord.length
    * beginWord, endWord, and wordList[i] consist of lowercase English letters.
    * beginWord != endWord
    * All the words in wordList are unique.
*/

#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /*
        queue(A..)
            given word A:
                check all the one-step transform of A => B:
                    if B in the wordList:
                        wordList.erase(B)
                        >> put to queue;
        */
        unordered_set<string> validWords(wordList.begin(), wordList.end());
        queue<string> currentTransforms;
        currentTransforms.push(beginWord);

        int step = 1;

        while (currentTransforms.size()) {
            int n = currentTransforms.size();
            for (int i = 0; i < n; i++) {
                string currentTransform = currentTransforms.front();
                currentTransforms.pop();

                if (currentTransform == endWord) {
                    return step;
                }

                vector<string> validTransforms = getTransforms(currentTransform, validWords);
                for (string transform : validTransforms) {
                    currentTransforms.push(transform);
                }
            }
            step += 1;
        }
        return 0;
    }

    vector<string> getTransforms(string origin, unordered_set<string>& validWords) {
        vector<string> result;
        for (int i = 0; i < origin.size(); i++) {
            for (char replacement = 'a'; replacement <= 'z'; replacement++) {
                string transform = origin.substr(0, i) + replacement + origin.substr(i + 1);

                if (validWords.count(transform)) {
                    result.push_back(transform);
                    validWords.erase(transform);
                }
            }
        }
        return result;
    }
};