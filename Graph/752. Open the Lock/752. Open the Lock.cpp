/*
Number: 752
Topic: Open the Lock
Date: 2021/10/31
Rate: Medium
https://leetcode.com/problems/open-the-lock/

You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

Constraints:
    * 1 <= deadends.length <= 500
    * deadends[i].length == 4
    * target.length == 4
    * target will not be in the list deadends.
    * target and deadends[i] consist of digits only.
*/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadends_set(deadends.begin(), deadends.end());
        
        unordered_set<string> seen;
        queue<string> candidates;
        candidates.push("0000");

        int step = 0;
        while (candidates.size()) {
            int nRoundSize = candidates.size();
            for (int n = 0; n < nRoundSize; n++) {
                string candidate = candidates.front();
                candidates.pop();
                if (seen.count(candidate) || deadends_set.count(candidate))
                    continue;
                if (candidate == target)
                    return step;
                seen.insert(candidate);
                for (int idx = 0; idx < 4; idx++) {
                    for (int diff : {-1, 1}) {
                        string newDigit = to_string((candidate[idx]-'0' + diff + 10) % 10);
                        string newCandidate = candidate.substr(0, idx) + newDigit + candidate.substr(idx + 1);
                        candidates.push(newCandidate);
                    }
                }
            }
            step += 1;
        }
        return -1;
    }
};