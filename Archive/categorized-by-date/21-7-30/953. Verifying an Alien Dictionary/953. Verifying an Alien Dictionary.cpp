/*
Number: 953
Topic: Verifying an Alien Dictionary
Date: 2021/7/30
Rate: Easy
https://leetcode.com/problems/verifying-an-alien-dictionary/

In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

Constraints:
* 1 <= words.length <= 100
* 1 <= words[i].length <= 20
* order.length == 26
* All characters in words[i] and order are English lowercase letters.
*/

class Solution {
private:
    const int ALPNUM = 26;
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> orders(ALPNUM, 0);
        for (int i = 0; i < ALPNUM; i++) {
            orders[order[i]-'a'] = i;
        }

        for (int i = 1; i < words.size(); i++) {
            if (greater(words[i-1], words[i], orders))
                return false;
        }
        return true;
    }

    bool greater(string s1, string s2, const vector<int>& orders) {
        int n = min(s1.size(), s2.size());

        for (int i = 0; i < n; i++) {
            if (orders[s1[i]-'a'] != orders[s2[i]-'a'])
                return orders[s1[i]-'a'] > orders[s2[i]-'a'];
        }

        return (s1.size() > s2.size());
    }
};