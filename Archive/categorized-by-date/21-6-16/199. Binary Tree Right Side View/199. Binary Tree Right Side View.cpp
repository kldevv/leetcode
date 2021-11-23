/*
Number: 199
Topic: Binary Tree Right Side View
Date: 2021/6/16
Rate: Medium
https://leetcode.com/problems/binary-tree-right-side-view/

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> out;
        overlapView(root, out, 0);

        return out;
    }

    void overlapView(TreeNode* root, vector<int>& out, int idx) {
        if (root == nullptr)
            return;
        if (out.size() <= idx)
            out.push_back(root->val);
        else
            out[idx] = root->val;
        overlapView(root->left, out, idx+1);
        overlapView(root->right, out, idx+1);
    }
};