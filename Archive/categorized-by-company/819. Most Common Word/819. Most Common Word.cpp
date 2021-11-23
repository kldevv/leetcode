/*
Number: 819
Topic: Most Common Word
Date: 2021/8/27
Rate: Easy
https://leetcode.com/problems/generate-parentheses/

Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.

The words in paragraph are case-insensitive and the answer should be returned in lowercase.

Constraints:
* 1 <= paragraph.length <= 1000
* paragraph consists of English letters, space ' ', or one of the symbols: "!?',;.".
* 0 <= banned.length <= 100
* 1 <= banned[i].length <= 10
* banned[i] consists of only lowercase English letters.
*/
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        
        for (char& c : paragraph)
            c = (isalpha(c)) ? tolower(c) : ' ';

        unordered_map<string, int> count;
        istringstream iss(paragraph);
        string word;
        int maxCount = 0;
        string result;

        while (iss >> word) {
            if (ban.count(word))
                continue;
            if (++count[word] > maxCount) {
                maxCount = count[word];
                result = word;
            }
        }
        return result;
    }
};