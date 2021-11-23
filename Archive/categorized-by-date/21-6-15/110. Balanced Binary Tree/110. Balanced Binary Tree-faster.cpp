/*
Number: 110
Topic: Balanced Binary Tree
Date: 2021/6/15
Rate: Easy
https://leetcode.com/problems/balanced-binary-tree/

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

Constraints:
* The number of nodes in the tree is in the range [0, 5000].
* -104 <= Node.val <= 10^4

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
    bool isBalanced(TreeNode* root) {
        return (countHeight(root) == 5300) ? false : true;
    }

    int countHeight(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (root->right == nullptr && root->left == nullptr)
            return 1;
        

        int right = countHeight(root->right);
        int left = countHeight(root->left);

        if (right == 5300 || left == 5300)
            return 5300;
        // do the check on the fly，不用每一層都在計算一次高度
        // 如果這邊已經 imbalanced，直接回傳一個會爆掉的高度就好
        return (abs(right-left) <= 1) ? max(right, left)+1 : 5300;
    }
};