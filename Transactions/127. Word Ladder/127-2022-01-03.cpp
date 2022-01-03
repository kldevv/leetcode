// 2022/01/03

#include <unordered_set>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordListCopied(wordList.begin(), wordList.end());

        if (wordListCopied.count(endWord) == 0 || beginWord.size() != endWord.size())
            return 0;
        if (beginWord == endWord)
            return 1;

        queue<string> trans;
        trans.push(beginWord);
        int step = 0;
        int n;
        while (n = trans.size()) {
            step += 1;
            for (int i = 0; i < n; i++) {
                string ori = trans.front();
                trans.pop();
                if (ori == endWord)
                    return step;
                for (int j = 0; j < ori.size(); j++) {
                    char oriChar = ori[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        ori[j] = c;
                        if (wordListCopied.count(ori)) {
                            wordListCopied.erase(ori);
                            trans.push(ori);
                        }
                    }
                    ori[j] = oriChar;
                }
            }
        }
        return 0;
    }
};