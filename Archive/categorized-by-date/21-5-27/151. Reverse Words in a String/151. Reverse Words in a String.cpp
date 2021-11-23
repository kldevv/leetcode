/*
Number: 151
Topic: Reverse Words in a String
Date: 2021/5/27
Rate: Medium
https://leetcode.com/problems/reverse-words-in-a-string/


Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Constraints:

* 1 <= s.length <= 104
* s contains English letters (upper-case and lower-case), digits, and spaces ' '.
* There is at least one word in s.

Follow up: Could you solve it in-place with O(1) extra space?
*/


class Solution {
public:
    string reverseWords(string s) {
        // 把多餘的空白都拿掉
        cleanSpace(s);
        // 先翻轉整個 string
        reverse(s, 0, s.size());
        int word_right = 0, word_left = 0;
        // 再個別翻轉每個字
        while (word_right < s.size()) {
            // 右邊先走
            while (word_right < s.size() && s[word_right] == ' ')
                word_right++;
            // 遇到字符後，建立左邊
            word_left = word_right;
            // 右邊繼續前進，直到遇到空白
            while (word_right < s.size() && s[word_right] != ' ')
                word_right++;
            if (word_left < s.size())
                reverse(s, word_left, word_right);
        }
        return s;
    }
    void reverse(string& s, int left, int right) {
        for (int i = 0; i < (right-left)/2; i++) {
            swap(s[left+i], s[right-i-1]);
        }
    }
    void cleanSpace(string& s) {
        // in-place 消除多餘的空白
        int idx = 0, new_idx = 0;
        while (idx < s.size()) {
            // 跳過多餘的空白
            while (idx < s.size() && s[idx] == ' ') {
                idx++;
            }
            // 除了第一個字跟最後一個字以外都加空白
            if (idx < s.size() && new_idx != 0) 
                s[new_idx++] = ' ';
            // 把字往前移動
            while (idx < s.size() && s[idx] != ' ') {
                s[new_idx++] = s[idx++];
            }
        }
        s = s.substr(0, new_idx);
    }
};






