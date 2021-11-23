/*
Number: 288
Topic: Unique Word Abbreviation
Date: 2021/7/26
Rate: Medium
https://leetcode.com/problems/unique-word-abbreviation/

The abbreviation of a word is a concatenation of its first letter, the number of characters between the first and last letter, and its last letter. If a word has only two characters, then it is an abbreviation of itself.

For example:

dog --> d1g because there is one letter between the first letter 'd' and the last letter 'g'.
internationalization --> i18n because there are 18 letters between the first letter 'i' and the last letter 'n'.
it --> it because any word with only two characters is an abbreviation of itself.
Implement the ValidWordAbbr class:

ValidWordAbbr(String[] dictionary) Initializes the object with a dictionary of words.
boolean isUnique(string word) Returns true if either of the following conditions are met (otherwise returns false):
There is no word in dictionary whose abbreviation is equal to word's abbreviation.
For any word in dictionary whose abbreviation is equal to word's abbreviation, that word and word are the same.

Constraints:
* 1 <= dictionary.length <= 3 * 104
* 1 <= dictionary[i].length <= 20
* dictionary[i] consists of lowercase English letters.
* 1 <= word.length <= 20
* word consists of lowercase English letters.
* At most 5000 calls will be made to isUnique.
*/

class ValidWordAbbr {
private:
    unordered_map<string, unordered_set<string>> umap;

    string getAbbr(string s) {
        string abbr = s[0] + to_string(s.size()) + s[s.size()-1];
        return abbr;
    }

public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (const string& s : dictionary) {
            string abbr = getAbbr(s);
            umap[abbr].insert(s);
        }
    }
    
    bool isUnique(string word) {
        string abbr = getAbbr(word);
        return !umap.count(abbr) || (umap[abbr].count(word) == umap[abbr].size());
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */