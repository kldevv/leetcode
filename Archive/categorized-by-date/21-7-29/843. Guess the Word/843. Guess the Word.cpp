/*
Number: 843
Topic: Guess the Word
Date: 2021/7/29
Rate: Hard
https://leetcode.com/problems/guess-the-word/

This is an interactive problem.

You are given an array of unique strings wordlist where wordlist[i] is 6 letters long, and one word in this list is chosen as secret.

You may call Master.guess(word) to guess a word. The guessed word should have type string and must be from the original list with 6 lowercase letters.

This function returns an integer type, representing the number of exact matches (value and position) of your guess to the secret word. Also, if your guess is not in the given wordlist, it will return -1 instead.

For each test case, you have exactly 10 guesses to guess the word. At the end of any number of calls, if you have made 10 or fewer calls to Master.guess and at least one of these guesses was secret, then you pass the test case.

Constraints:
* 1 <= wordlist.length <= 100
* wordlist[i].length == 6
* wordlist[i] consist of lowercase English letters.
* All the strings of wordlist are unique.
* secret exists in wordlist.
* numguesses == 10
*/

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
private:
    const int WORDLEN = 6;
    const int ATTEMPT = 10;

public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        vector<vector<int>> alphabetPos(WORDLEN, vector<int>(26, 0));
        for (const string& s : wordlist) {
            for (int i = 0; i < WORDLEN; i++) {
                alphabetPos[i][s[i]-'a'] += 1;
            }
        }

        vector<string> candidate(wordlist.begin(), wordlist.end());
        for (int k = 0; k < ATTEMPT; k++) {
            int bestMatch = 0;
            string curGuess = "";
            for (const string& s : candidate) {
                int curMatch = 0;
                for (int i = 0; i < WORDLEN; i++) {
                    curMatch += alphabetPos[i][s[i]-'a'];
                }

                if (curMatch > bestMatch) {
                    bestMatch = curMatch;
                    curGuess = s;
                }
            }
            int screteMatch = master.guess(curGuess);

            vector<string> nextCandidate;
            for (const string& s : candidate) {
                if (matchChar(curGuess, s) == screteMatch)
                    nextCandidate.push_back(s);
            }
            candidate = nextCandidate;
        }

    }

    int matchChar(const string& s1, const string& s2) {
        int count = 0;
        for (int i = 0; i < WORDLEN; i++) {
            count += (s1[i] == s2[i]);
        }
        return count;
    }
};