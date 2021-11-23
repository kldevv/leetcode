/*
Number: 156
Topic: Binary Tree Upside Down
Date: 2021/7/21
Rate: Medium
https://leetcode.com/problems/binary-tree-upside-down/

Given the root of a binary tree, turn the tree upside down and return the new root.

You can turn a binary tree upside down with the following steps:

1. The original left child becomes the new root.
2. The original root becomes the new right child.
3. The original right child becomes the new left child.

Constraints:
* The number of nodes in the tree will be in the range [0, 10].
* 1 <= Node.val <= 10
* Every right node in the tree has a sibling (a left node that shares the same parent). 

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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || (!root->left && !root->right))
            return root;

        TreeNode* newRoot = upsideDownBinaryTree(root->left);

        root->left->left = root->right;
        root->left->right = root;
        root->left = nullptr;
        root->right = nullptr;

        return newRoot;
    }
};