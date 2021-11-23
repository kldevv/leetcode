/*
Number: 863
Topic: All Nodes Distance K in Binary Tree
Date: 2021/9/24
Rate: Medium
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

Constraints:
    * The number of nodes in the tree is in the range [1, 500].
    * 0 <= Node.val <= 500
    * All the values Node.val are unique.
    * target is the value of one of the nodes in the tree.
    * 0 <= k <= 1000
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parents;
        findParents(root, parents);

        vector<int> results;
        unordered_set<TreeNode*> visited;
        distanceK(target, k, parents, visited, results);

        return results;
    }

    void distanceK(TreeNode* target, int k, unordered_map<TreeNode*, TreeNode*>& parents, unordered_set<TreeNode*> visited, vector<int>& results) {
        if (visited.count(target))
            return;

        visited.insert(target);
        if (k == 0) {
            results.push_back(target->val);
            return;
        }

        if (target->left)
            distanceK(target->left, k-1, parents, visited, results);
        if (target->right)
            distanceK(target->right, k-1, parents, visited, results);
        if (parents.count(target))
            distanceK(parents[target], k-1, parents, visited, results);
    }

    void findParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parents) {
        if (root->left) {
            parents[root->left] = root;
            findParents(root->left, parents);
        }

        if (root->right) {
            parents[root->right] = root;
            findParents(root->right, parents);
        }
    }
};
