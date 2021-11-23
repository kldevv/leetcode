/*
Number: 314
Topic: Binary Tree Vertical Order Traversal
Date: 2021/7/22
Rate: Medium
https://leetcode.com/problems/binary-tree-vertical-order-traversal/

Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Constraints:
* The number of nodes in the tree is in the range [0, 100].
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root)
            return {};

        int minCol = 0, maxCol = 0;
        getRange(root, 0, minCol, maxCol);
        int range = maxCol-minCol+1;

        vector<vector<int>> out(range);
        queue<pair<TreeNode*, int>> BFS;
        BFS.push({root, -minCol});

        while (!BFS.empty()) {
            TreeNode* node = BFS.front().first;
            int col = BFS.front().second;
            BFS.pop();

            out[col].push_back(node->val);

            if (node->left)
                BFS.push({node->left, col-1});
            if (node->right)
                BFS.push({node->right, col+1});
        }
        return out;
    }

    void getRange(TreeNode* root, int col, int& minCol, int& maxCol) {
        if (!root)
            return;
        minCol = min(minCol, col);
        maxCol = max(maxCol, col);
        getRange(root->left, col-1, minCol, maxCol);
        getRange(root->right, col+1, minCol, maxCol);
    }
};