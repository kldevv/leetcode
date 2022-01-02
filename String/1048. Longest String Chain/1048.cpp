// 2021/12/29
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int maxStrLen = 0;
        unordered_map<string, int> strLens;

        sort(words.begin(), words.end(), 
            [](string& s1, string& s2) { return s1.size() < s2.size(); });

        for (auto word : words) {
            int maxPreStrLen = 0;
            strLens[word] = 1;
            for (int i = 0; i < word.size(); i++) {
                string pred = word.substr(0, i) + word.substr(i + 1);
                if (strLens.count(pred)) {
                    strLens[word] = max(strLens[pred]+1, strLens[word]);
                }
            }
            maxStrLen = max(maxStrLen, strLens[word]);
        }
        return maxStrLen;
    }
};