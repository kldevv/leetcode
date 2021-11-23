/*
Number: 282
Topic: Expression Add Operators
Date: 2021/6/26
Rate: Hard
https://leetcode.com/problems/expression-add-operators/

Given a string num that contains only digits and an integer target, return all possibilities to add the binary operators '+', '-', or '*' between the digits of num so that the resultant expression evaluates to the target value.

Constraints:
* 1 <= num.length <= 10
* num consists of only digits.
* -2^31 <= target <= 2^31 - 1

*/

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> out;
        // 拆解數字
        for (int i = 1; i <= num.size(); i++) {
            // 如果轉換成數字後的長度和原本的不一樣，代表可能有 leading 0 的情況，直接 break
            string curStr = num.substr(0, i);
            long curVal = stol(curStr);

            if (to_string(curVal).size() != curStr.size())
                break;

            // 傳入第一次的運算
            addOperators(num, target, i, curVal, curVal, '*', curStr, out);
        }

        return out;
    }

    void addOperators(const string& num, const int& target, int i, long value, long preVal, char preOps, string temp, vector<string>& out) {
        // 長度都用盡，而且是 target
        if (i == num.size() && value == target) {
            out.push_back(temp);
            return;
        }

        // 長度用盡，但是不是 target
        if (i >= num.size())
            return;

        // 拆解數字
        for (int j = 1; j <= num.size()-i; j++) {
            string curStr = num.substr(i, j);
            long curVal = stol(curStr);

            if (to_string(curVal).size() != curStr.size())
                break;

            // 加法的話就可以直接 call
            addOperators(num, target, i+j, value+curVal, curVal, '+', temp+'+'+curStr, out);
            addOperators(num, target, i+j, value-curVal, curVal, '-', temp+'-'+curStr, out);
            
            // 乘法的話要小心，如果前面有 + 或 - ，要把最接近的那一項整個搶過來
            long newVal = value*curVal;
            if (preOps == '+') {
                curVal = preVal * curVal;
                newVal = (value-preVal) + curVal;
            }
            if (preOps == '-') {
                curVal = preVal * curVal;         
                newVal = (value+preVal) - curVal;
            }
            // 注意 preOps 還是一樣的，因為這邊用乘法上去，事實上整個項目的數字都變成一個在加減法後的大數字
            // 如果後面有連續的乘法還是要拿出來調整
            addOperators(num, target, i+j, newVal, curVal, preOps, temp+'*'+curStr, out);
        }
    }
};