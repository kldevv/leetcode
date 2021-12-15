/*
Number: 98
Topic: Validate Binary Search Tree
Date: 2021/12/3
Rate: Medium
https://leetcode.com/problems/validate-binary-search-tree/

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:
    * The left subtree of a node contains only nodes with keys less than the node's key.
    * The right subtree of a node contains only nodes with keys greater than the node's key.
    * Both the left and right subtrees must also be binary search trees.

Constraints:
    * The number of nodes in the tree is in the range [1, 104].
    * -231 <= Node.val <= 231 - 1
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
    bool isValidBST(TreeNode* root) {
        /*
        Valid:
            Base: (null)
                return true;
            Recurrence Relation:
                lower_bound < val < upper_bound
        */
        return isValidBST(root, nullptr, nullptr);
    }

    bool isValidBST(TreeNode* root, TreeNode* lower, TreeNode* upper) {
        if (root == nullptr)
            return true;

        if (lower != nullptr && lower->val >= root->val)
            return false;
        if (upper != nullptr && root->val >= upper->val)
            return false;
        return isValidBST(root->left, lower, root) && isValidBST(root->right, root, upper);
    }
};