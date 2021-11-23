/*
Number: 366
Topic: Find Leaves of Binary Tree
Date: 2021/7/21
Rate: Medium
https://leetcode.com/problems/find-leaves-of-binary-tree/

Given the root of a binary tree, collect a tree's nodes as if you were doing this:

Collect all the leaf nodes.
Remove all the leaf nodes.
Repeat until the tree is empty.

Constraints:
* The number of nodes in the tree is in the range [1, 100].
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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> out;
        findLeaves(root, out);

        return out;
    }

    int findLeaves(TreeNode* root, vector<vector<int>>& out) {
        if (!root)
            return -1;

        int level = max(findLeaves(root->left, out), findLeaves(root->right, out)) + 1;
        
        if (out.empty() || out.size() <= level)
            out.push_back({});
        out[level].push_back(root->val);

        return level;
    }
};