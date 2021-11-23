/*
Number: 358
Topic: Rearrange String k Distance Apart
Date: 2021/7/18
Rate: Hard
https://leetcode.com/problems/rearrange-string-k-distance-apart/

Given a string s and an integer k, rearrange s such that the same characters are at least distance k from each other. If it is not possible to rearrange the string, return an empty string "".

Constraints:
* 1 <= s.length <= 3 * 105
* s consists of only lowercase English letters.
* 0 <= k <= s.length
*/

class Solution {
public:
    string rearrangeString(string s, int k) {
        int n = s.size();
        if (!n || !k)
            return s;

        vector<int> dict(26, 0);
        for (int i = 0; i < n; i++) {
            dict[s[i]-'a'] += 1;
        }

        priority_queue<pair<int, char>> nextChar;
        for (int i = 0; i < dict.size(); i++) {
            if (!dict[i])
                continue;
            nextChar.push(make_pair(dict[i], i+'a'));
        }

        // greedy algorithm，剩餘出現次數最多的先放進來
        string out;
        while (!nextChar.empty()) {
            vector<pair<int, char>> temp;
            // 因為每個 character 都要 k 個距離，代表中間要有 k-1 個 character
            // 所以一次要 pop k 個不重複的 character，或是剩餘長度的 character
            for (int i = 0; i < min(k, n); i++) {
                if (nextChar.empty())
                    return "";

                pair<int, char> aChar = nextChar.top();
                nextChar.pop();

                out += aChar.second;

                if (--aChar.first > 0)
                    temp.push_back(aChar);

            }
            // 減去剩餘長度，並把剛剛使用過還有剩餘出現次數的 character 放回 pq 中
            n -= k;
            for (int i = 0; i < temp.size(); i++) {
                nextChar.push(move(temp[i]));
            }
        }
        return out;
    }
};