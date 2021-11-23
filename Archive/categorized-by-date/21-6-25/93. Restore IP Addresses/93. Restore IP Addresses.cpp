/*
Number: 93
Topic: Restore IP Addresses
Date: 2021/6/25
Rate: Medium
https://leetcode.com/problems/restore-ip-addresses/


Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can return them in any order.

A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single dots and cannot have leading zeros. For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 

Constraints:
* 0 <= s.length <= 3000
* s consists of digits only.
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> out;
        restoreIpAddresses(s, 0, "", 0, out);
        return out;
    }

    void restoreIpAddresses(const string& s, int i, string temp, int count, vector<string>& out) {
        if (count > 4 || i > s.size())
            return;

        if (count == 4 && i == s.size()) {
            out.push_back(temp);
            return;
        }

        if (count > 0)
            temp += '.';

        int num = 0;
        for (int j = 0; j <= 2; j++) {
            if (i + j > s.size())
                break;

            num *= 10;
            num += s[i+j]-'0';

            if (num > 255)
                break;

            restoreIpAddresses(s, i+j+1, temp+to_string(num), count+1, out);

            if (num == 0)
                break;
        }
    }
};