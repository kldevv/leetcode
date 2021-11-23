/*
Number: 132
Topic: Palindrome Partitioning II
Date: 2021/6/6
Rate: Hard

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Constraints:
* 1 <= s.length <= 2000
* s consists of lower-case English letters only.

*/

class Solution {
public:
    int minCut(string s) {
        if (s.size() <= 1)
            return 0;

        vector<int> minCut;
        // dp 儲存，結尾為 i 時最少需要的 cut ，加上長度為 0 時，所以有 size+1 個值
        for (int i = 0; i <= s.size(); i++) {
            // 每個地方最少都需要 i-1 個 cut （代表每個字母都分開），然後故意把 0 設成 -1，這樣後面的運算才方便 (整個字串都是 palindrome 時，-1+1 = 0)
            // aabaa , i = 2, j = 2
            minCut.push_back(i-1);
        }

        for (int i = 0; i < s.size(); i++) {
            // odd-length 
            for (int j = 0; i+j<s.size() && i-j>=0; j++) {
                // 不是 palindrome 時就提早退出
                if (s[i+j] != s[i-j])
                    break;
                // i+j+1 等於 i-j 時的最小 cut + 一個 palindrome (1)
                minCut[i+j+1] = min(minCut[i+j+1], minCut[i-j]+1);                
            }
            // even-length
            for (int j = 0; i+j<s.size() && i-j+1>=0; j++) {
                // 不是 palindrome 時就提早退出
                if (s[i+j] != s[i-j+1])
                    break;
                // i+j+1 等於 i-j-1 時的最小 cut + 一個 palindrome (1)
                minCut[i+j+1] = min(minCut[i+j+1], minCut[i-j+1]+1);
            }
        }
        return minCut[s.size()];
    }
};