/*
Number: 187
Topic: Repeated DNA Sequences
Date: 2021/6/6
Rate: Medium

The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

Constraints:
* 1 <= s.length <= 10^5
* s[i] is either 'A', 'C', 'G', or 'T'.

*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<int> first;
        unordered_set<int> second;
        vector<string> out;

        // tc: O(N)
        // 因為只有四個字母，可以用 binary 2^2 = 4 位數來表達
        vector<int> map(26, -1);
        map['A'-'A'] = 0; // ... 00
        map['C'-'A'] = 1; // ... 01
        map['G'-'A'] = 2; // ... 10
        map['T'-'A'] = 3; // ... 11

        int temp = 0, trans = 0;
        // 用來消除最前面的字母，保持個長度為 10 的 sliding window
        // 11000000000000000000 = 00111111111111111111
        // 在用 & operator 可以消除最前面的兩個 bit
        int mask = ~(3 << 18);
        for (int i = 0; i < s.size(); i++) {
            trans = map[s[i]-'A'];

            // 消除最前面的字母
            temp &= mask;
            // 目前的整個字母往前推兩格，空出來的空間給新的字母加入
            temp <<= 2;
            temp |= trans;

            if (i < 9)
                continue;

            // 如果看過第一次，但是沒看過第二次，就是可以 push 進答案裡的
            if (first.count(temp) && !second.count(temp)) {
                second.insert(temp);
                // 追蹤的是尾巴，所以要反推 9 個為頭
                out.push_back(s.substr(i-9, 10));
            }
            first.insert(temp);
        }

        return out;
    }
};