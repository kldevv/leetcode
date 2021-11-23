/*
Number: 96
Topic: Unique Binary Search Trees II
Date: 2021/6/19
Rate: Medium
https://leetcode.com/problems/unique-binary-search-trees-ii/

Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

Constraints:
* 1 <= n <= 8

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
    unordered_map<int, vector<TreeNode*>> umap;

    vector<TreeNode*> generateTrees(int n) {
        if (!n)
            return {};

        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int head, int tail) {
        int key = head*10 + tail;
        if (umap.count(key))
            return umap[key];

        vector<TreeNode*> combs;

        if (head > tail) {
            combs.push_back(nullptr);
            return combs;
        }

        for (int i = head; i <= tail; i++) {
            // get all the right combs and left combs
            vector<TreeNode*> leftCombs = generateTrees(head, i-1);
            vector<TreeNode*> rightCombs = generateTrees(i+1, tail);

            // cartesian products
            for (auto left : leftCombs) {
                for (auto right : rightCombs) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    combs.push_back(root);
                }
            }
        }
        umap[key] = combs;
        return combs;
    }
};