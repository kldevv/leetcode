/*
Number: 386
Topic: Lexicographical Numbers
Date: 2021/6/11
Rate: Medium
https://leetcode.com/problems/lexicographical-numbers/

Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space. 


Constraints:
* 1 <= n <= 5 * 10^4

*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> out(n, 0);
        int curr = 1;
        for (int i = 0; i < n; i++) {
            out[i] = curr;
            // lexicographical sorted 下一個大的數字就是 curr * 10
            if (curr * 10 <= n) {
                curr *= 10;
            } else {
                // 如果 the least significant digit + 1 超過範圍，那就 the second least significant digit+1
                if (curr == n) 
                    curr /= 10;
                // 在下一個大的數字就是 the least significant digit + 1
                curr += 1;

                // e.g. n = 1200, curr = 199 時，下一個數字是 2 ，這時候直接加 1 會變成 200；要把 trailing zero 殺掉
                while (curr % 10 == 0) {
                    curr /= 10;
                }
            } 
        }
        return out;
    }
};