/*
Number: 179
Topic: Largest Number
Date: 2021/5/28
Rate: Medium
https://leetcode.com/problems/largest-number/

Given a list of non-negative integers nums, arrange them such that they form the largest number.

Note: The result may be very large, so you need to return a string instead of an integer.

Constraints:
* 1 <= nums.length <= 100
* 0 <= nums[i] <= 109

*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for (const int& num : nums) {
                temp.push_back(to_string(num));
        }
        // lexicographical sort array，傳入自己的 function s1+s2>s2+s1
        sort(temp.begin(), temp.end(), [](string& s1, string& s2) {return s1+s2>s2+s1;});
        string out;
        for (const string& s : temp) {
            out += s;
        }
        // 如果有很多個 0 ，而且都在排頭 e.g. 00000 時只留下一個 0
        while (out.size() > 1 && out[0] == '0')
            out.erase(0, 1);
        return out;
    }
};