/*
Number: 285
Topic: Inorder Successor in BST
Date: 2021/7/21
Rate: Medium
https://leetcode.com/problems/find-leaves-of-binary-tree/

Given the root of a binary search tree and a node p in it, return the in-order successor of that node in the BST. If the given node has no in-order successor in the tree, return null.

The successor of a node p is the node with the smallest key greater than p.val.


Constraints:
* The number of nodes in the tree is in the range [1, 104].
* -105 <= Node.val <= 105
* All Nodes will have unique values.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        return inorderSuccessor(root, p, nullptr);
    }

    TreeNode* inorderSuccessor(TreeNode* node, TreeNode* p, TreeNode* nextHop) {
        if (node->val == p->val) {
            // 沒有右邊的 node 了，要往 nextHop 跳去
            if (!node->right)
                return nextHop;

            // 右邊還有 node，找右邊最左邊的 node
            node = node->right;
            while (node->left) {
                node = node->left;
            }
            return node;
        }

        // 找尋目標的 node
        if (node->val > p->val)
            // 往左邊 traverse 時，nextHop 就是這個 node 拉
            return inorderSuccessor(node->left, p, node);
        else
            // 往右邊 traverse 時，nextHop 是接續上一個 nextHop
            return inorderSuccessor(node->right, p, nextHop);
    }
};