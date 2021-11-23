/*
Number: 272
Topic: Closest Binary Search Tree Value II
Date: 2021/7/21
Rate: Hard
https://leetcode.com/problems/closest-binary-search-tree-value-ii/

Given the root of a binary search tree, a target value, and an integer k, return the k values in the BST that are closest to the target. You may return the answer in any order.

You are guaranteed to have only one unique set of k values in the BST that are closest to the target.

Constraints:
* The number of nodes in the tree is n.
* 1 <= k <= n <= 104.
* 0 <= Node.val <= 109
* -109 <= target <= 109
 
Follow up: Assume that the BST is balanced. Could you solve it in less than O(n) runtime (where n = total nodes)?
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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        queue<int> range;
        closestKValues(root, target, k, range);

        vector<int> out(k, 0);
        for (int i = 0; i < k; i++) {
            out[i] = range.front();
            range.pop();
        }
        return out;
    }

    void closestKValues(TreeNode* root, double target, int k, queue<int>& range) {
        if (!root)
            return;

        closestKValues(root->left, target, k, range);
        if (range.size() == k) {
            if (abs(range.front() - target) > abs(root->val - target))
                range.pop();
            else
                return;
        }

        range.push(root->val);
        closestKValues(root->right, target, k, range);
    }
};