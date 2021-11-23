/*
Number: 1152
Topic: Analyze User Website Visit Pattern
Date: 2021/9/15
Rate: Medium
https://leetcode.com/problems/analyze-user-website-visit-pattern/

You are given two string arrays username and website and an integer array timestamp. All the given arrays are of the same length and the tuple [username[i], website[i], timestamp[i]] indicates that the user username[i] visited the website website[i] at time timestamp[i].

A pattern is a list of three websites (not necessarily distinct).

    * For example, ["home", "away", "love"], ["leetcode", "love", "leetcode"], and ["luffy", "luffy", "luffy"] are all patterns.

The score of a pattern is the number of users that visited all the websites in the pattern in the same order they appeared in the pattern.

    * For example, if the pattern is ["home", "away", "love"], the score is the number of users x such that x visited "home" then visited "away" and visited "love" after that.
    * Similarly, if the pattern is ["leetcode", "love", "leetcode"], the score is the number of users x such that x visited "leetcode" then visited "love" and visited "leetcode" one more time after that.
    * Also, if the pattern is ["luffy", "luffy", "luffy"], the score is the number of users x such that x visited "luffy" three different times at different timestamps.

Return the pattern with the largest score. If there is more than one pattern with the same largest score, return the lexicographically smallest such pattern.

Constraints:
    * 3 <= username.length <= 50
    * 1 <= username[i].length <= 10
    * timestamp.length == username.length
    * 1 <= timestamp[i] <= 109
    * website.length == username.length
    * 1 <= website[i].length <= 10
    * username[i] and website[i] consist of lowercase English letters.
    * It is guaranteed that there is at least one user who visited at least three websites.
    * All the tuples [username[i], timestamp[i], website[i]] are unique.
*/
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, map<int, string>> userHistory; // pattern->username
        unordered_map<string, int> patternCount; // user-> website history
        int n = username.size();
        char delimiter = (char)('a'-1);

        // group username, website, and sort by timestamp
        for (int i = 0; i < n; i++) {
            userHistory[username[i]][timestamp[i]] = website[i];
        }

        int maxCount = 0;
        string result = "";
        for (auto history : userHistory) {
            unordered_set<string> patterns;
            auto end = history.second.end();
        
            for (auto it = history.second.begin(); it != end; it++) {
                for (auto it2 = next(it); it2 != end; it2++) {
                    for (auto it3 = next(it2); it3 != end; it3++) {
                        patterns.insert(it->second + delimiter + it2->second + delimiter + it3->second);
                    }
                }
            }

            for (string pattern : patterns) {
                if (++patternCount[pattern] > maxCount) {
                    maxCount = patternCount[pattern];
                    result = pattern;
                }
                else if (patternCount[pattern] == maxCount && pattern < result) {
                    result = pattern;
                }
            }
        }
        // split string
        vector<string> results;
        for (int i = 0; i < result.size(); i++) {
            int j = i;
            while (j < result.size() && result[j] != delimiter)
                j++;
            results.push_back(result.substr(i, j-i));
            i = j;
        }
        return results;
    }
};
