/*
Number: 1110
Topic: Delete Nodes And Return Forest
Date: 2021/8/20
Rate: Medium
https://leetcode.com/problems/delete-nodes-and-return-forest/

Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

Constraints:
* The number of nodes in the given tree is at most 1000.
* Each node has a distinct value between 1 and 1000.
* to_delete.length <= 1000
* to_delete contains distinct values between 1 and 1000.
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> out;
        unordered_set<int> toDelete;

        for (int n : to_delete) {
            toDelete.insert(n);
        }

        delNodes(root, toDelete, out, true);

        return out;
    }

    TreeNode* delNodes(TreeNode* root, unordered_set<int>& toDelete, vector<TreeNode*>& out, bool isRoot) {
        if (!root)
            return nullptr;

        bool beDeleted = toDelete.count(root->val);

        if (!beDeleted && isRoot)
            out.push_back(root);

        root->right = delNodes(root->right, toDelete, out, beDeleted);
        root->left = delNodes(root->left, toDelete, out, beDeleted);

        return (beDeleted) ? nullptr : root;
    }
};