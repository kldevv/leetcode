/*
Number: 285
Topic: Inorder Successor in BST
Date: 2021/11/17
Rate: Medium
https://leetcode.com/problems/inorder-successor-in-bst/

Given the root of a binary search tree and a node p in it, return the in-order successor of that node in the BST. If the given node has no in-order successor in the tree, return null.

The successor of a node p is the node with the smallest key greater than p.val.

Constraints:
    * The number of nodes in the tree is in the range [1, 104].
    * -105 <= Node.val <= 105
    * All Nodes will have unique values.
*/

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

/*

            3
    2               5
1               4       6



*/

class Solution {
   public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = nullptr;
        while (root) {
            if (p->val < root->val) {
                successor = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return successor;
    }
};