/*
Number: 100
Topic: Same Tree
Date: 2021/6/12
Rate: Medium
https://leetcode.com/problems/same-tree/

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Constraints:
* The number of nodes in both trees is in the range [0, 100].
* -104 <= Node.val <= 104

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 兩個是 null 回傳 true
        if (p == nullptr && q == nullptr)
            return true;
        // 只有一個是 null，回傳 false
        else if (p == nullptr || q == nullptr)
            return false;

        // 檢查左右和自己
        if (p->val != q->val)
            return false;
        if (!(isSameTree(p->left, q->left)))
            return false;
        if (!(isSameTree(p->right, q->right)))
            return false;

        // 沒出錯就一樣
        return true;
    }
};