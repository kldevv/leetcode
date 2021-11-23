/*
Number: 111
Topic: Minimum Depth of Binary Tree
Date: 2021/6/15
Rate: Easy
https://leetcode.com/problems/maximum-depth-of-binary-tree/

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Constraints:
* The number of nodes in the tree is in the range [0, 105].
* -1000 <= Node.val <= 1000


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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        return minDepth(root, 0);
        
    }

    int minDepth(TreeNode* root, int count) {
        if (root == nullptr)
            return INT_MAX;

        count += 1;
        if (root->right == nullptr && root->left == nullptr)
            return count;

        return min(minDepth(root->right, count), minDepth(root->left, count));
    }
};