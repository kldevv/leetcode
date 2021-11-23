/*
Number: 107
Topic: Binary Tree Level Order Traversal II
Date: 2021/6/15
Rate: Medium
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

Constraints:
* The number of nodes in the tree is in the range [0, 2000].
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};

        vector<vector<int>> out;
        vector<int> temp;

        queue<TreeNode*> q;
        TreeNode* curr;
        int n;

        q.push(root);
        while (!q.empty()) {
            n = q.size();
            temp.clear();
            // 處理上一次的那些 Node，Strict BFS
            for (int i = 0; i < n; i++) {
                curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if (curr->left != nullptr)
                    q.push(curr->left);
                if (curr->right != nullptr)
                    q.push(curr->right);
            }
            out.push_back(temp);
        }

        reverse(out.begin(), out.end())
        return out;
    }
};