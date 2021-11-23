/*
Number: 270
Topic: Closest Binary Search Tree Value
Date: 2021/7/21
Rate: Easy
https://leetcode.com/problems/closest-binary-search-tree-value/

Given the root of a binary search tree and a target value, return the value in the BST that is closest to the target.

Constraints:
* The number of nodes in the tree is in the range [1, 10^4].
* 0 <= Node.val <= 10^9
* -10^9 <= target <= 10^9
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
    int closestValue(TreeNode* root, double target) {
        // 最遠的距離
        int winner = root->val;
        closestValue(root, target, winner);

        return winner;
    }

    void closestValue(TreeNode* root, double target, int& winner) {
        if (!root)
            return;

        winner = (abs(winner - target) < abs(root->val - target)) ? winner : root->val;

        // 十分逼近法
        if (root->val > target)
            closestValue(root->left, target, winner);
        else
            closestValue(root->right, target, winner);
    }
};