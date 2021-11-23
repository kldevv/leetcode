/*
Number: 94
Topic: Binary Tree Inorder Traversal
Date: 2021/6/11
Rate: Medium
https://leetcode.com/problems/binary-tree-inorder-traversal/

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Constraints:
* The number of nodes in the tree is in the range [0, 100].
* -100 <= Node.val <= 100

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        inorderTraversal(root, out);
        return out;
        
    }
    void inorderTraversal(TreeNode* root, vector<int>& out) {
        // 左邊沒了就回傳
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left, out);
        // 左邊都進去了就換自己囉
        out.push_back(root->val);
        inorderTraversal(root->right, out);
    }
};