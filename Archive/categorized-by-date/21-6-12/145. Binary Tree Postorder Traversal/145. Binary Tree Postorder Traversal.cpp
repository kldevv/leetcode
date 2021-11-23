/*
Number: 145
Topic: Binary Tree Postorder Traversal
Date: 2021/6/12
Rate: Easy
https://leetcode.com/problems/binary-tree-postorder-traversal/

Given the root of a binary tree, return the postorder traversal of its nodes' values.

Constraints:
* The number of the nodes in the tree is in the range [0, 100].
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> out;
        postorderTraversal(root, out);
        return out;
    }

    void postorderTraversal(TreeNode* root, vector<int>& out) {
        if (root == nullptr) {
            return;
        }
        // left -> right -> middle
        postorderTraversal(root->left, out);
        postorderTraversal(root->right, out);
        out.push_back(root->val);
    }
};