/*
Number: 301
Topic: Remove Invalid Parentheses
Date: 2021/11/29
Rate: Hard
https://leetcode.com/problems/remove-invalid-parentheses/

Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return all the possible results. You may return the answer in any order.

Constraints:
    * 1 <= s.length <= 25
    * s consists of lowercase English letters and parentheses '(' and ')'.
    * There will be at most 20 parentheses in s.
*/
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   private:
    bool isValid(string& s) {
        int stack = 0;
        for (char c : s) {
            if (c == '(')
                stack += 1;
            if (c == ')')
                stack -= 1;

            if (stack < 0)
                return false;
        }
        return stack == 0;
    }

   public:
    vector<string> removeInvalidParentheses(string s) {
        /*
        BFS;

        for each level:
            if s is valid:
                result.put(s)
                found = true
            
            if not found:
                take any ( or ):
                (to avoid duplicate, in consecutive ( or ) we decide to take the last one)
                    >> nextBatch
        %%%%%%%%%%%%%%%
        Complexity:
            T(n) = O(2^s.size() * s.size())
                    - in the worst case, we check every element of the power set of string. For each string we check, we use O(n)
            S(n) = O(C(s.size(), s.size()/2))
                    - in the worst case, we need to store 2*C(s.size(), s.size()/2) elements in the queue

        */

        unordered_set<string> seen;
        vector<string> results;

        queue<string> strs;
        strs.push(s);
        bool found = false;

        while (strs.size()) {
            int queueSize = strs.size();
            for (int i = 0; i < queueSize; i++) {
                string toValid = strs.front();
                strs.pop();

                // If the shortest path is found, stop searching for the next level
                if (isValid(toValid)) {
                    results.push_back(toValid);
                    found = true;
                }

                if (!found) {
                    for (int skipIdx = 0; skipIdx < toValid.size(); skipIdx++) {
                        if ((toValid[skipIdx] == '(' || toValid[skipIdx] == ')') && (skipIdx == toValid.size() - 1 || toValid[skipIdx + 1] != toValid[skipIdx])) {
                            string truncated = toValid.substr(0, skipIdx) + toValid.substr(skipIdx + 1);
                            if (seen.count(truncated) == 0) {
                                seen.insert(truncated);
                                strs.push(truncated);
                            }
                        }
                    }
                }
            }
        }
        return results;
    }
};