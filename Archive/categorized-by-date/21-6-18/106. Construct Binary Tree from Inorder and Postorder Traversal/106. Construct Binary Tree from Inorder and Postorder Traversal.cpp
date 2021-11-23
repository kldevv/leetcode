/*
Number: 106
Topic: Construct Binary Tree from Inorder and Postorder Traversal
Date: 2021/6/18
Rate: Medium
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/


Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Constraints:
* 1 <= inorder.length <= 3000
* postorder.length == inorder.length
* -3000 <= inorder[i], postorder[i] <= 3000
* inorder and postorder consist of unique values.
* Each value of postorder also appears in inorder.
* inorder is guaranteed to be the inorder traversal of the tree.
* postorder is guaranteed to be the postorder traversal of the tree.

 
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inPos = inorder.size()-1, postPos = postorder.size()-1;
        return buildTree(inorder, postorder, INT_MAX, inPos, postPos);
    }

    // O(n) 兩個 array 從尾走到頭而已
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int stop, int& inPos, int& postPos) {
        // 全部的 node 都生成了，直接回傳 nullptr
        if (postPos == -1)
            return nullptr;
        // 活用 inorder -> 最左邊的最後一個
        // 活用 postorder -> 最上面的在最後一個，往前走就會一直往右邊加，除非碰到最右邊的 node，也就是 inorder 的最後一個
        // inOrder[inPos] == stop，代表上一個 node 的右邊已經沒有 node 了 （右邊 DFS 到底了)，該 move on 到左邊了
        if (inorder[inPos] == stop) {
            inPos--;
            return nullptr;
        }

        TreeNode* node = new TreeNode(postorder[postPos--]);
        // 往右邊加 node，直到碰到最右邊的
        node->right = buildTree(inorder, postorder, node->val, inPos, postPos);
        node->left = buildTree(inorder, postorder, stop, inPos, postPos);
        return node;
    }
};