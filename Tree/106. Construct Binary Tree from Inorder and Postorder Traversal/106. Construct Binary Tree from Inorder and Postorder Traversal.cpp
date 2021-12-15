/*
Number: 106
Topic: Construct Binary Tree from Inorder and Postorder Traversal
Date: 2021/12/4
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

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<int> inorder;
    vector<int> postorder;
    unordered_map<int, int> inorderIdxOf;
    int rootIdx;

   public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        /*
        inorder: left -> root -> right
        postorder: left -> right -> root

        Example:
            - inorder = [9,3,15,20,7]
            - postorder = [9,15,7,20,3]

        reversely use postorder as root to break the inorder into right subtree and left subtree

        if (inStart > inEnd)
            return nullptr

        val = postorder[rootIdx]
        rootIdx -= 1

        root = new Node(val)

        root->right = func(inorderIdxOf(val) + 1, inEnd)
        root->left = func(inStart, inorderIdxOf(val)-1)
        */
        this->inorder = inorder;
        this->postorder = postorder;
        rootIdx = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIdxOf[inorder[i]] = i;
        }
        return buildTree(0, inorder.size() - 1);
    }

    TreeNode* buildTree(int inStart, int inEnd) {
        if (inStart > inEnd)
            return nullptr;

        int val = postorder[rootIdx--];
        TreeNode* root = new TreeNode(val);

        root->right = buildTree(inorderIdxOf[val] + 1, inEnd);
        root->left = buildTree(inStart, inorderIdxOf[val] - 1);

        return root;
    }
};