/*
Number: 337
Topic: House Robber III
Date: 2021/6/15
Rate: Medium
https://leetcode.com/problems/house-robber-iii/


The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

Constraints:
* The number of nodes in the tree is in the range [1, 10^4].
* 0 <= Node.val <= 10^4


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
    int rob(TreeNode* root) {
        int r = 0, l = 0;
        return rob(root, r, l);
    }

    int rob(TreeNode* root, int& prevGrandLeft, int& prevGrandRight) {
        // 回傳這一層的最佳值
        // 順便更新下一層的最佳值
        // 所以 n 層可以拿到 n + 1 層的最佳值，又可以拿到 n + 2 層的最佳值
        // 因為在呼叫 n + 1 層的 function 時，又要呼叫 n + 2 層的 function

        if (!root)
            return 0;

        int rl = 0, rr = 0, lr = 0, ll = 0;
        prevGrandRight = rob(root->right, rl, rr);
        prevGrandLeft = rob(root->left, ll, lr);

        return max(root->val+rl+rr+ll+lr, prevGrandLeft+prevGrandRight);
    }
};