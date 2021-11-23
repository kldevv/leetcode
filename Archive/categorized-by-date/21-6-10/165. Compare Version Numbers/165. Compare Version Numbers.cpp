/*
Number: 165
Topic: Compare Version Numbers
Date: 2021/6/10
Rate: Medium
https://leetcode.com/problems/compare-version-numbers/

Given two version numbers, version1 and version2, compare them.

Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits and may contain leading zeros. Every revision contains at least one character. Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example 2.5.33 and 0.1 are valid version numbers.

To compare version numbers, compare their revisions in left-to-right order. Revisions are compared using their integer value ignoring any leading zeros. This means that revisions 1 and 001 are considered equal. If a version number does not specify a revision at an index, then treat the revision as 0. For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.

Return the following:

* If version1 < version2, return -1.
* If version1 > version2, return 1.
* Otherwise, return 0.

Constraints:
* 1 <= version1.length, version2.length <= 500
* version1 and version2 only contain digits and '.'.
* version1 and version2 are valid version numbers.
* All the given revisions in version1 and version2 can be stored in a 32-bit integer.

*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1 = 0, v2 = 0;
        int num1 = 0, num2 = 0;
        // 跑到有結果，或是所有 revision 的跑過後
        while (v1 < version1.size() || v2 < version2.size()) {
            // 還有 revision 的話就擷取這次的 revision number，沒有的話就預設是 0
            while (v1 < version1.size() && version1[v1] != '.') {
                num1 *= 10;
                num1 += version1[v1++]-'0';
            }
            while (v2 < version2.size() && version2[v2] != '.') {
                num2 *= 10;
                num2 += version2[v2++]-'0';
            }

            if (num1 > num2)
                return 1;
            else if (num1 < num2)
                return -1;
            // reset，也跳過 character "." 
            num1 = 0, num2 = 0;
            v1++, v2++;
        }
        // 全部 revision 比較過後沒有結果，代表相等
        return 0;
    }
};