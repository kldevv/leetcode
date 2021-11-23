/*
Number: 113
Topic: Path Sum II
Date: 2021/6/14
Rate: Medium
https://leetcode.com/problems/path-sum-ii/

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where each path's sum equals targetSum.

A leaf is a node with no children.

Constraints:
* The number of nodes in the tree is in the range [0, 5000].
* -1000 <= Node.val <= 1000
* -1000 <= targetSum <= 1000


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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> out;
        vector<int> temp;
        pathSum(root, targetSum, temp, out);

        return out;
    }

    void pathSum(TreeNode* root, int targetSum, vector<int>& temp, vector<vector<int>>& out) {
        if (root == nullptr)
            return;

        temp.push_back(root->val);
        targetSum -= (root->val);

        if (targetSum == 0 && root->right == nullptr && root->left == nullptr) {
            out.push_back(temp);
        } else {
            pathSum(root->right, targetSum, temp, out);
            pathSum(root->left, targetSum, temp, out);
        }
        temp.pop_back();
    }
};