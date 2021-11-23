/*
Number: 127
Topic: Word Ladder
Date: 2021/7/7
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


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        
        queue<string> q;
        q.push(beginWord);
        int out = 0;

        // BFS，找最短的層數
        while (!q.empty()) {
            // 每過一層就 +1
            out += 1;

            int n = q.size();
            for (int i = 0; i < n; i++) {
                // 這層的都 traverse 完
                // 為了不要再跑回來，把這個字丟掉，因為已經用過了，如果後來其他的字又跑到這個字，也沒關係，因為我們可以更直接地跑到這個字(層數更少)，後面的結果也運算過了
                set.erase(q.front());
                // 如果這層有一個字符合，就達到目的了
                if (q.front() == endWord)
                    return out;
                // 找這個字的每一個位子，換成任何一個其他的英文字母
                for (int pos = 0; pos < q.front().size(); pos++) {
                    string word = q.front();
                    for (int j = 0; j < 26; j++) {
                        word[pos] = 'a' + j;
                        if (set.count(word)) {
                            q.push(word);
                        }
                    }
                }
                q.pop();
            }         
        }
        return 0;
    }
};