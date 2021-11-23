/*
Number: 257
Topic: Binary Tree Paths
Date: 2021/6/14
Rate: Easy
https://leetcode.com/problems/binary-tree-paths/

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.



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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> out;
        string temp;

        binaryTreePaths(root, temp, out);
        return out;
    }

    void binaryTreePaths(TreeNode* root, string temp, vector<string>& out) {
        // copying string can also use a vector and convert to string when pushing to output vector
        if (temp.empty())
            temp += to_string(root->val);
        else
            temp += "->" + to_string(root->val);

        // 左右都是 null 代表是 leaft node，儲存結果吧
        if (root->right == nullptr && root->left == nullptr)
            out.push_back(temp);
        // 如果不是 leaf 就繼續往下
        if (root->right != nullptr)
            binaryTreePaths(root->right, temp, out);
        if (root->left != nullptr)
            binaryTreePaths(root->left, temp, out);
    }
};