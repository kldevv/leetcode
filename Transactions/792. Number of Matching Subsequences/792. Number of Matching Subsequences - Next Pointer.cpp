/*
Number: 792
Topic: Number of Matching Subsequences - Next Pointer
Date: 2021/11/26
Rate: Medium
https://leetcode.com/problems/number-of-matching-subsequences/

Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
    * For example, "ace" is a subsequence of "abcde".

Constraints:
    * 1 <= s.length <= 5 * 104
    * 1 <= words.length <= 5000
    * 1 <= words[i].length <= 50
    * s and words[i] consist of only lowercase English letters.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int numMatchingSubseq(string s, vector<string>& words) {
        /*
        Instantiate:
            buckets[c] = all the word starting with c
        
        For c in s:
            currentBucket = buckets[c]
            bucket[c].empty()
            For word in currentBucket:
                if len(word) == 1:
                    result += 1
                else:
                    buckets[word[1]].append(word[1:])

        %%%%%%%%%%%%%%%
        Complexity:
            - Time:
                O(s.size() + words.size() + SUM_{i=0}^{words.size()-1}{words[i].size()})
                = O(s.size() + SUM_{i=0}^{words.size()-1}{words[i].size()})
                    for words.size() < SUM_{i=0}^{words.size()-1}{words[i].size()}
            - Space:
                O(words.size())
        */
        vector<vector<pair<int, int>>> buckets;
        buckets = buildBuckets(words);

        int countMatchSubseq = 0;
        for (char c : s) {
            auto currentBucket = buckets[c - 'a'];
            buckets[c - 'a'].clear();
            for (auto p : currentBucket) {
                int wordIdx = p.first;
                int currentIdxPointer = p.second + 1;

                if (currentIdxPointer == words[wordIdx].size())
                    countMatchSubseq += 1;
                else {
                    buckets[words[wordIdx][currentIdxPointer] - 'a'].push_back(make_pair(wordIdx, currentIdxPointer));
                }
            }
        }
        return countMatchSubseq;
    }

    vector<vector<pair<int, int>>> buildBuckets(vector<string>& words) {
        /*
        bucket[idx] = a list of (wordIdx, currentIdxPointer)

        %%%%%%%%%%%%%%%
        Complexity:
            - Time:
                O(words.size())
            - Space:
                O(words.size())
        */
        vector<vector<pair<int, int>>> buckets(26, vector<pair<int, int>>());

        for (int wordIdx = 0; wordIdx < words.size(); wordIdx++) {
            int bucketIdx = words[wordIdx][0] - 'a';
            buckets[bucketIdx].push_back(make_pair(wordIdx, 0));
        }
        return buckets;
    }
};