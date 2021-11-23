/*
Number: 114
Topic: Flatten Binary Tree to Linked List
Date: 2021/10/15
Rate: Medium
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

Given the root of a binary tree, flatten the tree into a "linked list":
* The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
* The "linked list" should be in the same order as a pre-order traversal of the binary tree.

Constraints:
    * The number of nodes in the tree is in the range [0, 2000].
    * -100 <= Node.val <= 100

Follow up: Can you flatten the tree in-place (with O(1) extra space)?
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
    void flatten(TreeNode* root) {
        TreeNode* curNode = root;

        while (curNode) {
            if (curNode->left != nullptr) {
                
                TreeNode* leftRightMost = curNode->left;
                while (leftRightMost->right != nullptr) {
                    leftRightMost = leftRightMost->right;
                }

                leftRightMost->right = curNode->right;
                curNode->right = curNode->left;
                curNode->left = nullptr;
            }
            curNode = curNode->right;
        }
    }
};