/*
Number: 99
Topic: Recover Binary Search Tree
Date: 2021/6/17
Rate: Medium
https://leetcode.com/problems/recover-binary-search-tree/


You are given the root of a binary search tree (BST), where exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Follow up: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

Constraints:
* The number of nodes in the tree is in the range [2, 1000].
* -231 <= Node.val <= 231 - 1
 
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
    void recoverTree(TreeNode* root) {
        bool again;
        
        // keep correcting the tree until it's perfect
        do {
            again = correctTree(root, nullptr, nullptr);
        } while (again);
    }

    bool correctTree(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (root == nullptr)
            return false;

        // if the node's val is less than the minNode's value, they should be swapped 
        if (minNode != nullptr && root->val < minNode->val) {
            swap(root->val, minNode->val);
            return true;
        }
        // if the node's val is greater than the maxNode's value, they should be swapped 
        if (maxNode != nullptr && root->val > maxNode->val) {
            swap(root->val, maxNode->val);
            return true;
        }

        // if correction happens down the tree, pass the message
        return correctTree(root->right, root, maxNode) || correctTree(root->left, minNode, root);
    }
};