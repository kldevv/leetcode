/*
Number: 144
Topic: Binary Tree Preorder Traversal
Date: 2021/6/10
Rate: Easy
https://leetcode.com/problems/binary-tree-preorder-traversal/

Given the root of a binary tree, return the preorder traversal of its nodes' values.


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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> out;
        preorderTraversal(root, out);
        return out;
    }

    void preorderTraversal(TreeNode* root, vector<int>& out) {
        if (root == nullptr)
            return;
        out.push_back(root->val);
        preorderTraversal(root->left, out);
        preorderTraversal(root->right, out);
    }
};