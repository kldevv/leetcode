// 2021/12/30

#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendsCopied(deadends.begin(), deadends.end());

        // init state is dead
        if (deadendsCopied.count("0000"))
            return -1;

        queue<string> cand;
        cand.push("0000");

        int step = 0;
        int n;
        while (n = cand.size()) {
            for (int i = 0; i < n; i++) {
                string lock = cand.front();
                cand.pop();

                if (lock == target)
                    return step;
                for (int slot = 0; slot < 4; slot++) {
                    char ori = lock[slot];                
                    for (int delta : {1, -1}) {
                        char newly = (((ori-'0' + delta) + 10) % 10) + '0';
                        lock[slot] = newly;
                        if (deadendsCopied.count(lock) == 0) {
                            deadendsCopied.insert(lock);
                            cand.push(lock);
                        }
                    }
                    lock[slot] = ori;
                }
            }  
            step += 1;
        }
        return -1;
    }
};