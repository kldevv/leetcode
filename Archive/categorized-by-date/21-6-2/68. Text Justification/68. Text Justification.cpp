/*
Number: 68
Topic: Text Justification
Date: 2021/6/2
Rate: Medium
https://leetcode.com/problems/text-justification/


Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

Note:

* A word is defined as a character sequence consisting of non-space characters only.
* Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
* The input array words contains at least one word.

Constraints:
* 1 <= s.length <= 2 * 10^5
* s consists only of printable ASCII characters.
 
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> out;
        vector<string> arr;

        int count = 0, remain = 0, space = 0, extra = 0;
        string temp;

        for (int i = 0; i < words.size(); i++) {
            // 如果 count (目前有的字數) + arr.size() (目前有的字數代表已經有的空格+1) + 新加的字數
            // 沒有超過，就加新的字
            if (count+arr.size()+words[i].size() <= maxWidth) {
                arr.push_back(words[i]);
                count += words[i].size();
            } else {
                remain = maxWidth - count;
                // 只有一個字，向左對齊
                if (arr.size() == 1) {
                    temp = arr[0];
                    temp += string(remain, ' ');
                // 多個字
                } else if (arr.size() > 1) {
                    temp = arr[0];
                    // n 個字就有 n-1 個空格
                    space = remain / (arr.size()-1);
                    extra = remain % (arr.size()-1);

                    for (int i = 1; i < arr.size(); i++) {
                        // 除不盡的部分，前 extra 個空格都 + 1
                        if (i <= extra)
                            temp += string(space+1, ' ');
                        else
                            temp += string(space, ' ');
                        temp += arr[i];
                    }
                }
                out.push_back(temp);
                arr.clear();
                arr.push_back(words[i]);
                count = words[i].size();
            }
        }
        // 處理最後一行
        temp = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            temp += " ";
            temp += arr[i];
        }
        temp += string(maxWidth-temp.size(), ' ');
        out.push_back(temp);
        return out;
    }
};