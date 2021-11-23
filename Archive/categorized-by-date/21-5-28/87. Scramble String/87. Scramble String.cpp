/*
Number: 87
Topic: Scramble String
Date: 2021/5/28
Rate: Hard
https://leetcode.com/problems/scramble-string/

We can scramble a string s to get a string t using the following algorithm:

1. If the length of the string is 1, stop.
2. If the length of the string is > 1, do the following:
    * Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
    * Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
    * Apply step 1 recursively on each of the two substrings x and y.

Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

Constraints:
* s1.length == s2.length
* 1 <= s1.length <= 30
* s1 and s2 consist of lower-case English letters.

*/

// time complexity analysis is down below

class Solution {
public:
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool>umap;
        return isScramble(umap, s1, s2);
    }

    bool isScramble(unordered_map<string, bool>&umap, string s1, string s2) {
        // 檢查是否已經測試過這兩個 string e.g. s1 = abc/abc, s2 = bac/bac 時可以不用計算第二次的 (abc, bac)
        if (umap.count(s1+s2)) {
            return umap[s1+s2];
        // 同上
        } else if (umap.count(s2+s1)) {
            return umap[s2+s1];
        // 是否完全一樣
        } else if (s1 == s2) {
            umap[s1+s2] = true;
            return true;
        }

        // 檢查是否有一樣的 character set
        vector<int> temp(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            temp[s1[i]-'a']++;
            temp[s2[i]-'a']--;
        }
        for (const int& num : temp) {
            if (num) {
                umap[s1+s2] = false;
                return false;
            }
        }

        // recursive 把 s1 從 k 點分開， s1[:k] 可能和 s2[:k] 或是 s2[n-k:] 是 scramble string
        int n = s1.size();
        for (int i = 1; i < s1.size(); i++) {
            if (isScramble(umap, s1.substr(0, i), s2.substr(0, i)) && isScramble(umap, s1.substr(i), s2.substr(i))) {
                umap[s1+s2] = true;
                return true;

            } else if (isScramble(umap, s1.substr(0, i), s2.substr(n-i)) && isScramble(umap, s1.substr(i), s2.substr(0, n-i))) {
                umap[s1+s2] = true;
                return true;               
            }
        }
        umap[s1+s2] = false;
        return false;
    }
};


/* tc analysis
For string of size n take time to be T(n) for it
We are starting from i=1 and going till n-1
This line of code if( isScramble(s1.substring(0, i), s2.substring(0, i)) && isScramble(s1.substring(i), s2.substring(i)) )
is T(i) + T(n-i)
and this line of code just below if( isScramble(s1.substring(0, i), s2.substring(s1.length() - i)) && isScramble(s1.substring(i), s2.substring(0, s1.length() - i)))
is again T(i) + T(n-i)

So basically for T(n) we have:
T(n) = for i in 1 to n-1 : +2*(T(i) + T(n-i))
i.e.
T(n) = 2*(T(1) + T(n-1) + T(2) + T(n-2) + ... + T(n-1) + T(1)) ,
now we have two equal sequences T(1) to T(n-1) from left to right and T(n-1) to T(1) from right to left. So above equation can be written as
T(n) = 2 * 2(T(1) + T(2) + ...+ T(n-2) + T(n-1))
T(n) = 4 * (T(1) + T(2) + ...+ T(n-2) ) + 4 * T(n-1)

if we substitute n-1 in place of n above we get T(n-1) = 4 * (T(1) + T(2) + ...+ T(n-2) ) , using this in the above equation we get
T(n) = T(n-1) + 4 * T(n-1)
T(n) = 5 * T(n-1)

If we open this we get
T(n) = 5 * 5 * T(n-2) = 5 * 5 * 5 * T(n-3) = 5 * 5 * ... * 5 (n times)
so T(n) = O(5^n)
*/