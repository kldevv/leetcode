/*
Number: 418
Topic: Sentence Screen Fitting
Date: 2021/8/10
Rate: Medium
https://leetcode.com/problems/sentence-screen-fitting/

Given a rows x cols screen and a sentence represented as a list of strings, return the number of times the given sentence can be fitted on the screen.

The order of words in the sentence must remain unchanged, and a word cannot be split into two lines. A single space must separate two consecutive words in a line.

Constraints:
* 1 <= sentence.length <= 100
* 1 <= sentence[i].length <= 10
* sentence[i] consists of lowercase English letters.
* 1 <= rows, cols <= 2 * 104
*/

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        unordered_map<int, int> umap;
        int n = sentence.size();
        int out = 0;
        int idx = 0;
        while (rows > 0) {
            if (umap.count(idx)) {
                idx += umap[idx];
                out += (idx / n);
                idx %= n;
            } 
            else {
                int start = idx;
                int totalSize = 0;
                int space = 0;
                while (totalSize+space+sentence[idx].size() <= cols) {
                    totalSize += sentence[idx++].size();
                    space += 1;
                    out += (idx / n);
                    idx %= n;
                }
                umap[start] = space;
            }
            rows -= 1;
        }
        return out;
    }
};