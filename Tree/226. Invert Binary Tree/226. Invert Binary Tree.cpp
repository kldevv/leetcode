/*
Number: 226
Topic: Invert Binary Tree
Date: 2021/12/7
Rate: Medium
https://leetcode.com/problems/invert-binary-tree/

Given the root of a binary tree, invert the tree, and return its root.

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
    TreeNode* invertTree(TreeNode* root) {
        /*
        Base cases:
            root == nullptr
                return;
        root->right = root->left;
        root->left = root->right
        invertTree(root->right & left)
        */

        if (root == nullptr)
            return nullptr;

        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    }
};