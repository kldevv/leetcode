/*
Number: 333
Topic: Largest BST Subtree
Date: 2021/7/22
Rate: Medium
https://leetcode.com/problems/largest-bst-subtree/

Given the root of a binary tree, find the largest subtree, which is also a Binary Search Tree (BST), where the largest means subtree has the largest number of nodes.

A Binary Search Tree (BST) is a tree in which all the nodes follow the below-mentioned properties:

The left subtree values are less than the value of their parent (root) node's value.
The right subtree values are greater than the value of their parent (root) node's value.
Note: A subtree must include all of its descendants.

Follow up: Can you figure out ways to solve it with O(n) time complexity?

Constraints:
* The number of nodes in the tree is in the range [0, 104].
* -104 <= Node.val <= 104

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
    int largestBSTSubtree(TreeNode* root) {
        int left, right, numNode, maxNodeNum = 0;
        largestBSTSubtree(root, left, right, numNode, maxNodeNum);

        return maxNodeNum;
    }

    bool largestBSTSubtree(TreeNode* root, int& lower, int& upper, int& numNodeIfBST, int& maxNodeNum) {
        if (!root) {
            numNodeIfBST = 0;
            return true;
        }

        int leftLower, leftUpper, leftNumNodeIfBST;
        bool leftBST = largestBSTSubtree(root->left, leftLower, leftUpper, leftNumNodeIfBST, maxNodeNum);
        int rightLower, rightUpper, rightNumNodeIfBST;
        bool rightBST = largestBSTSubtree(root->right, rightLower, rightUpper, rightNumNodeIfBST, maxNodeNum);

        if (leftBST && rightBST) {
            if ((!root->left || leftUpper < root->val) && (!root->right || root->val < rightLower)) {
                numNodeIfBST = leftNumNodeIfBST + rightNumNodeIfBST + 1;
                maxNodeNum = max(maxNodeNum, numNodeIfBST);

                lower = (root->left) ? leftLower : root->val;
                upper = (root->right) ? rightUpper : root->val;
                return numNodeIfBST;
            }
        }
        return false;
    }
};