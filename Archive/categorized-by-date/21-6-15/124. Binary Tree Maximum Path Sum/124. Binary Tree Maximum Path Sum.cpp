/*
Number: 124
Topic: Binary Tree Maximum Path Sum
Date: 2021/6/15
Rate: Easy
https://leetcode.com/problems/balanced-binary-tree/

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any path.

Constraints:
* The number of nodes in the tree is in the range [1, 3 * 10^4].
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
    int maxPathSum(TreeNode* root) {
        int _max = INT_MIN;
        maxPathSum(root, _max);

        return _max;
    }

    // 回傳單條路最大的可能值
    int maxPathSum(TreeNode* root, int& _max) {
        if (root == nullptr)
            return 0;

        // 可以走左邊跟走右邊，也可以斷在這，所以最小值會是 0，負的就不管他
        int left = max(maxPathSum(root->left, _max), 0);
        int right = max(maxPathSum(root->right, _max), 0);

        // 在這邊如果從左邊走到右邊，是最大就更新
        _max = max(_max, left+right+root->val);

        // 選一條數字最大的路(左或右)，往上傳
        return max(left, right) + root->val;
    }
};