/*
Number: 572
Topic: Subtree of Another Tree
Date: 2021/9/1
Rate: Easy
https://leetcode.com/problems/subtree-of-another-tree/

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

Constraints:
* The number of nodes in the root tree is in the range [1, 2000].
* The number of nodes in the subRoot tree is in the range [1, 1000].
* -104 <= root.val <= 104
* -104 <= subRoot.val <= 104
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
    bool isMatch(TreeNode* root, TreeNode* subRoot) {
        if ((root == nullptr) && (subRoot == nullptr))
            return true;
        if ((root == nullptr) || (subRoot == nullptr) || root->val != subRoot->val)
            return false;

        return isMatch(root->right, subRoot->right) && isMatch(root->left, subRoot->left);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr)
            return false;
        if (isMatch(root, subRoot))
            return true;
        return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
    }
};