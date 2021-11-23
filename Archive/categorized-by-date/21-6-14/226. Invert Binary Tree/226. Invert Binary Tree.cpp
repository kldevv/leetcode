/*
Number: 226
Topic: Invert Binary Tree
Date: 2021/6/14
Rate: Easy
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
        swapRightLeft(root);
        return root;

    }

    void swapRightLeft(TreeNode* root) {
        if (root == nullptr)
            return;

        swap(root->right, root->left);
        swapRightLeft(root->right);
        swapRightLeft(root->left);
    }
};