/*
Number: 105
Topic: Construct Binary Tree from Preorder and Inorder Traversal
Date: 2021/6/18
Rate: Medium
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Constraints:
* 1 <= preorder.length <= 3000
* inorder.length == preorder.length
* -3000 <= preorder[i], inorder[i] <= 3000
* preorder and inorder consist of unique values.
* Each value of inorder also appears in preorder.
* preorder is guaranteed to be the preorder traversal of the tree.
* inorder is guaranteed to be the inorder traversal of the tree.

 
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int prePos = 0, inPos = 0;
        return buildTree(preorder, inorder, INT_MAX, prePos, inPos);
    }

    // O(n) 兩個 array 從頭走到尾而已
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int stop, int& prePos, int& inPos) {
        // 全部的 node 都生成了，直接回傳 nullptr
        if (prePos == preorder.size())
            return nullptr;
        // inOrder[inPos] == stop，代表上一個 node 的左邊已經沒有 node 了 (左邊 DFS 到底了)，該 move on 到右邊了
        if (inorder[inPos] == stop) {
            inPos++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[prePos++]);
        node->left = buildTree(preorder, inorder, node->val, prePos, inPos);
        node->right = buildTree(preorder, inorder, stop, prePos, inPos);
        return node;
    }
};