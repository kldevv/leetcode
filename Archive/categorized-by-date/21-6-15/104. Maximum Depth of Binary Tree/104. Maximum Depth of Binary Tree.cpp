/*
Number: 104
Topic: Maximum Depth of Binary Tree
Date: 2021/6/15
Rate: Easy
https://leetcode.com/problems/maximum-depth-of-binary-tree/

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Constraints:
* The number of nodes in the tree is in the range [0, 10^4].
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        return maxDepth(root, 0);
    }

    int maxDepth(TreeNode* root, int count) {
        if (root == nullptr)
            return INT_MIN;

        count += 1;
        if (root->right == nullptr && root->left == nullptr)
            return count;

        return min(maxDepth(root->right, count), maxDepth(root->left, count));
    }
};