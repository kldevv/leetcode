/*
Number: 273
Topic: Integer to English Words
Date: 2021/5/29
Rate: Hard
https://leetcode.com/problems/integer-to-english-words/

Convert a non-negative integer num to its English words representation.


Constraints:
* 0 <= num <= 231 - 1

*/

// 沒什麼好講的，我照抄這篇的
// https://leetcode.com/problems/integer-to-english-words/discuss/70632/Recursive-Python

class Solution {
public:
    string numberToWords(int num) {
        if (!num)
            return "Zero";
        vector<string> to19 =  {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        vector<string> tens = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> out;
        numberToWords(num, to19, tens, out);

        string str;
        for (int i = 0; i < out.size(); i++) {
            if (i != 0)
                str += " " + out[i];
            else
                str += out[i];
        }
        return str;
    }

    void numberToWords(int num, vector<string> to19, vector<string> tens, vector<string>& out) {
        if (num <= 0)
            return;
        else if (num < 20) {
            out.push_back(to19[num-1]);
        } else if (num < 100) {
            out.push_back(tens[num/10-2]);
            numberToWords(num%10, to19, tens, out); 
        } else if (num < 1000) {
            out.push_back(to19[num/100-1]);
            out.push_back("Hundred");
            numberToWords(num%100, to19, tens, out);
        } else {
            vector<string> big_num = {"Thousand", "Million", "Billion"};
            for (int i = 1; i <= big_num.size(); i++) {
                if (num < pow(1000, (i+1))) {
                    numberToWords(num / (int)pow(1000,i), to19, tens, out);
                    out.push_back(big_num[i-1]);
                    numberToWords(num % (int)pow(1000,i), to19, tens, out);
                    break;
                }
            }
        }
    }
};