/*
Number: 230
Topic: Kth Smallest Element in a BST
Date: 2021/6/17
Rate: Medium
https://leetcode.com/problems/kth-smallest-element-in-a-bst/

Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.

Constraints:
* The number of nodes in the tree is n.
* 1 <= k <= n <= 10^4
* 0 <= Node.val <= 10^4
 
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
public:
    int kthSmallest(TreeNode* root, int k) {
        // just use the stack
        // tc: O(k), sc: O(h);
        
        stack<TreeNode*> stk;
        TreeNode* kSmallest;

        pushLeft(root, stk);

        while (k != 0) {
            kSmallest = stk.top();
            stk.pop();
            k -= 1;
            pushLeft(kSmallest->right, stk);
        }

        return (kSmallest->val);
    }

    void pushLeft(TreeNode* iterator, stack<TreeNode*>& stk) {
        while (iterator != nullptr) {
            stk.push(iterator);
            iterator = iterator->left;
        }
    }
};