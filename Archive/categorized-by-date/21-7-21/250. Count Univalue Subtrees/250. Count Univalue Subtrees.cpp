/*
Number: 250
Topic: Count Univalue Subtrees
Date: 2021/7/21
Rate: Medium
https://leetcode.com/problems/count-univalue-subtrees/

Given the root of a binary tree, return the number of uni-value subtrees.

A uni-value subtree means all nodes of the subtree have the same value.

Constraints:
* The numbrt of the node in the tree will be in the range [0, 1000].
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
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        countUnivalSubtrees(root, count);
        
        return count;
    }

    bool countUnivalSubtrees(TreeNode* root, int& count) {
        if (!root)
            return true;

        bool thisSubtree = ((!root->right || root->val == root->right->val) && (!root->left || root->val == root->left->val));
        bool leftSubtree = countUnivalSubtrees(root->left, count);
        bool rightSubtree = countUnivalSubtrees(root->right, count);

        if (thisSubtree && leftSubtree && rightSubtree) {
            count += 1;
            return true;
        }

        return false;
    }
};