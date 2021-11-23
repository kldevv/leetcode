/*
Number: 115
Topic: Distinct Subsequences
Date: 2021/6/4
Rate: Hard
https://leetcode.com/problems/distinct-subsequences/

Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

It is guaranteed the answer fits on a 32-bit signed integer.

Constraints:
* 1 <= s.length, t.length <= 1000
* s and t consist of English letters.

*/

class Solution {
public:
    int numDistinct(string s, string t) {
        // dp 問題，dp[i][j] 代表 match 到 t[:j+1] 和 s[:i+1] 時，有多少個 matched subsequence
        
        vector<vector<double>> dp;
        for (int i = 0; i <= t.size(); i++) {
            vector<double> temp;
            for (int j = 0; j <= s.size(); j++) {
                // 第一行接為 0 ，因為 "" 是所以 string 的 subsequence，可是只有一個
                if (i == 0)
                    temp.push_back(1);
                // 第二行開始的第一列，都會是零，因為沒有 string 是 "" 的 substring
                // 其他的我們也先放 0
                else
                    temp.push_back(0);
            }
            dp.push_back(temp);
        }

        for (int i = 1; i <= t.size(); i++) {
            for (int j = 1; j <= s.size(); j++) {
                // 從第二行第二列開始
                // 如果 t[j] 不等於 s[i] 時，subsequence 的數量不變
                // 當等於時，等於到 s[i-1] 的 subsequence 數量加上包含 s[i] 的數量 (也就是選到 dp[i-1][j-1] 時的數量)

                dp[i][j] = (t[i-1] == s[j-1]) ? dp[i][j-1] + dp[i-1][j-1] : dp[i][j-1];
            }
        }
        return dp[t.size()][s.size()];
    }
};

// e.g.
// S 0123....j
// T +----------+
//   |1111111111|
// 0 |0         |
// 1 |0         |
// 2 |0         |
// . |0         |
// . |0         |
// i |0         |

// S: [acdabefbc] and T: [ab]

//            *  *
//       S = [acdabefbc]
// mem[1] = [0111222222]

//                *  * ]
//       S = [acdabefbc]
// mem[1] = [0111222222]
// mem[2] = [0000022244]

      // S = [a   b    ]
      // S = [a      b ]
      // S = [   ab    ]
      // S = [   a   b ]
