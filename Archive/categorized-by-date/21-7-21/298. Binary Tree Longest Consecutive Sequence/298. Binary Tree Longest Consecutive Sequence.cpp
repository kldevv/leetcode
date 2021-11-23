/*
Number: 298
Topic: Binary Tree Longest Consecutive Sequence
Date: 2021/7/21
Rate: Medium
https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/

Given the root of a binary tree, return the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path needs to be from parent to child (cannot be the reverse).

Constraints:
* The number of nodes in the tree is in the range [1, 3 * 104].
* -3 * 10^4 <= Node.val <= 3 * 10^4
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
    int longestConsecutive(TreeNode* root) {
        int maxLen = INT_MIN;
        longestConsecutive(root, root->val, 0, maxLen);
        return maxLen;
    }

    void longestConsecutive(TreeNode* root, int target, int count, int& maxLen) {
        if (!root)
            return;

        if (root->val == target)
            count += 1;
        else
            count = 1;

        maxLen = max(maxLen, count);
        longestConsecutive(root->left, root->val+1, count, maxLen);
        longestConsecutive(root->right, root->val+1, count, maxLen);
    }
};