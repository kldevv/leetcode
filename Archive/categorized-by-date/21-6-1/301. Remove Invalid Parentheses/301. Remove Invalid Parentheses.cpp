/*
Number: 301
Topic: Remove Invalid Parentheses
Date: 2021/6/1
Rate: Hard
https://leetcode.com/problems/remove-invalid-parentheses/

Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return all the possible results. You may return the answer in any order.

Constraints:
* 1 <= s.length <= 25
* s consists of lowercase English letters and parentheses '(' and ')'.
* There will be at most 20 parentheses in s.
 
*/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> out;
        unordered_set<string> set;
        
        queue<string> q;
        q.push(s);

        bool stopAtLevel = false;

        // 做一個 BFS
        while (!q.empty()) {
            string temp = q.front();
            q.pop();

            // 一樣的 string 已經測試過了，不需要重複的 string
            if (set.count(temp))
                continue;
            set.insert(temp);

            // 如果這個 level 有 string 是 valid 的，就不要再往下一層去搜尋
            // 雖然當這個 level 裡面前面有 result 是 invalid (他的 children 會被加到 queue) 而後面是 valid 時
            // 前面加的那個 children 還是會被測試過一次，不過他們不會是 valid 的，因為當他們的 parent (size=n) valid 時，至少要在下兩層 size=n-2 時才會 valid (要 remove 一對 ())
            if (isValid(temp)) {
                stopAtLevel = true;
                out.push_back(temp);
            }
            // 停止搜尋
            if (stopAtLevel)
                continue;
            // 隨機 remove 掉任何一個括弧，進到下一層
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i] != '(' && temp[i] != ')')
                    continue;
                q.push(temp.substr(0, i)+temp.substr(i+1));
            }
        }
        return out; 
    }


    bool isValid(string s) {
        int count = 0;
        for (const char& c : s) {
            if (c == '(')
                count++;
            else if (c == ')')
                count--;
            if (count < 0)
                return false;
        }
        return (count == 0);
    }
};