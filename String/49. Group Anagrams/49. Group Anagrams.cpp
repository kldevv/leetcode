/*
Number: 49
Topic: Group Anagrams
Date: 2021/11/30
Rate: Medium
https://leetcode.com/problems/group-anagrams/

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Constraints:
    * 1 <= strs.length <= 104
    * 0 <= strs[i].length <= 100
    * strs[i] consists of lowercase English letters.
*/
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   private:
    string getIdentity(string words) {
        vector<int> countChar(26, 0);
        for (char c : words) {
            countChar[c - 'a'] += 1;
        }
        return hashCount(countChar);
    }

    string hashCount(vector<int>& count) {
        string hash = "";
        for (int i : count) {
            hash += ("#" + to_string(i));
        }
        return hash;
    }

   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
        anagrams -> same count of characters

        1. count all the words (vector) -> string
            - #count of character(a) + #count of character(b) + ...
        2. put the same count together (unordered_map[string] = vector)
        */
        unordered_map<string, vector<string>> buckets;

        for (string word : strs) {
            buckets[getIdentity(word)].push_back(word);
        }

        vector<vector<string>> results;

        for (auto pair : buckets) {
            results.push_back(pair.second);
        }
        return results;
    }
};