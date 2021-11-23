/*
Number: 255
Topic: Verify Preorder Sequence in Binary Search Tree
Date: 2021/7/21
Rate: Medium
https://leetcode.com/problems/binary-tree-upside-down/

Given an array of unique integers preorder, return true if it is the correct preorder traversal sequence of a binary search tree.

Constraints:
* 1 <= preorder.length <= 104
* 1 <= preorder[i] <= 104
* All the elements of preorder are unique.

Follow up: Could you do it using only constant space complexity?

*/

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int stkIdx = -1;
        // 代表目前這個 node 最小的值是什麼～
        int lowerBound = INT_MIN;
        for (int& val : preorder) {
            // 現在已經跑到這個 node 的右邊了，如果值又小於這個 node 的話就毀了！
            if (val <= lowerBound)
                return false;

            // 當遇到比較大的值，就代表我們在某個 node 的 right subtree 了，把他小的都丟掉，並且持續紀錄 lowerBound
            while (stkIdx >= 0 && preorder[stkIdx] < val)
                lowerBound = preorder[stkIdx--];

            // 遇到比較小的值，就繼續 push 進 stack 中
            preorder[++stkIdx] = val;
        }
        return true;
    }
};