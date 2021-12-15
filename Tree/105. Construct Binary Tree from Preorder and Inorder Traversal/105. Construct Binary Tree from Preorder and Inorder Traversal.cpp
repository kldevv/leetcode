/*
Number: 105
Topic: Construct Binary Tree from Preorder and Inorder Traversal
Date: 2021/12/4
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

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<int> preorder;
    vector<int> inorder;
    int nextRootIdx;
    unordered_map<int, int> valIdxAtInorder;

   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /*
        preorder = root -> left -> right
        inorder = left -> root -> right

        Example:
            pre = [3,5,9,20,15,7]
            in = [9,3,5,15,20,7]

        Use preorder val to break the inorder into left subtree and rightsubtree

        if inStart > inEnd:
            return nullptr

        val = preorder[preorderPointer++]
        root = new Node(val)

        root->left = func(inStart, inIdx[val]-1)
        root->right = func(inIdx[val]+1, inEnd)

        return root;
        */
        nextRootIdx = 0;
        this->preorder = preorder;
        this->inorder = inorder;
        for (int i = 0; i < inorder.size(); i++) {
            this->valIdxAtInorder[inorder[i]] = i;
        }

        return buildTree(0, inorder.size() - 1);
    }

    TreeNode* buildTree(int inStart, int inEnd) {
        if (inStart > inEnd)
            return nullptr;

        int val = preorder[nextRootIdx++];
        TreeNode* root = new TreeNode(val);

        root->left = buildTree(inStart, valIdxAtInorder[val] - 1);
        root->right = buildTree(valIdxAtInorder[val] + 1, inEnd);
        return root;
    }
};