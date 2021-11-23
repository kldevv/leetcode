/*
Number: 937
Topic: Reorder Data in Log Files
Date: 2021/8/3
Rate: Easy
https://leetcode.com/problems/reorder-data-in-log-files/

You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.

There are two types of logs:

Letter-logs: All words (except the identifier) consist of lowercase English letters.
Digit-logs: All words (except the identifier) consist of digits.
Reorder these logs so that:

The letter-logs come before all digit-logs.
The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
The digit-logs maintain their relative ordering.
Return the final order of the logs.

Constraints:
* 1 <= logs.length <= 100
* 3 <= logs[i].length <= 100
* All the tokens of logs[i] are separated by a single space.
* logs[i] is guaranteed to have an identifier and at least one word after the identifier.
*/

class Solution {
private:
    struct comparator {
        bool operator()(const string& s1, const string& s2) {
            string words1 = getWord(s1);
            string words2 = getWord(s2);
            return (words1 < words2 || (words1 == words2 && s1 <= s2));
        }
        string getWord(const string& s) {
            int i = 0;
            while (!isspace(s[i]))
                i++;
        return s.substr(i+1);
        }
    };

    bool isDigitWord(string s) {
        string words = getWord(s);
        for (int i = 0; i < words.size(); i++) {
            if (!isdigit((int)words[i]) && !isspace((int)words[i]))
                return false;
        }
        return true;
    }

    string getWord(const string& s) {
        int i = 0;
        while (!isspace(s[i]))
            i++;
        return s.substr(i+1);
    }

public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = logs.size();

        vector<string> out(n, "");

        int dig = n-1, log = 0;
        for (int i = n-1; i >= 0; i--) {
            if (isDigitWord(logs[i]))
                out[dig--] = logs[i];
            else
                out[log++] = logs[i];
        }
        sort(out.begin(), out.begin()+log, comparator());
        return out;
    }
};