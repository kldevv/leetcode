/*
Number: 556
Topic: Next Greater Element III
Date: 2021/8/3
Rate: Medium
https://leetcode.com/problems/next-greater-element-iii/

Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

Constraints:
* 1 <= n <= 231 - 1
*/

class Solution {
public:
    int nextGreaterElement(int n) {
        string word = to_string(n);
        nextPermutationWord(word);

        long out = stol(word);
        cout << out;

        return (out <= n || out > INT_MAX) ? -1 : out;
    }

    void nextPermutationWord(string& s) {
        int n = s.size();
        int i = n-2;
        for (; i >= 0; i--) {
            if (s[i] < s[i+1]) {
                for (int j = n-1; j > i; j--) {
                    if (s[j] > s[i]) {
                        swap(s[i], s[j]);
                        reverse(s.begin()+i+1, s.end());
                        return;
                    }
                }
            }
        }
    }
};