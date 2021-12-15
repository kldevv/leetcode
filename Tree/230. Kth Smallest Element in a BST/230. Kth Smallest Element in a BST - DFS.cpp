/*
Number: 230
Topic: Kth Smallest Element in a BST - DFS
Date: 2021/12/5
Rate: Medium
https://leetcode.com/problems/kth-smallest-element-in-a-bst/

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Constraints:
    * The number of nodes in the tree is n.
    * 1 <= k <= n <= 104
    * 0 <= Node.val <= 104

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
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
   private:
    int k;
    int result;

   public:
    int kthSmallest(TreeNode* root, int k) {
        /*
        searchLeft(root->left)

        currentNode == kth Node;
        k -= 1

        searchRight(root->right)
        */
        this->k = k;
        kthSmallest(root);
        return result;
    }

    void kthSmallest(TreeNode* root) {
        if (root == nullptr)
            return;

        kthSmallest(root->left);

        if (k == 1)
            result = root->val;
        k -= 1;

        kthSmallest(root->right);
    }
};