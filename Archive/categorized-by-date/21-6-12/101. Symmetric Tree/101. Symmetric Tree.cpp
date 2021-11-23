/*
Number: 101
Topic: Symmetric Tree
Date: 2021/6/12
Rate: Medium
https://leetcode.com/problems/same-tree/

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Constraints:
* The number of nodes in the tree is in the range [1, 1000].
* -100 <= Node.val <= 100

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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        int n;
        stack<TreeNode*> stk;
        TreeNode* curr;

        while (!stk.empty()) {
            n = q.size();
            // strict BFS
            for (int i = 0; i < n; i++) {
                curr = q.front();
                q.pop();
                // first half
                if (i < n/2) {
                    stk.push(curr);
                // second half
                } else {
                    if ((stk.top() != nullptr && curr != nullptr) && (stk.top()->val != curr->val)) {
                        return false;
                    } else if (stk.top() == nullptr && curr != nullptr) {
                        return false;
                    } else if (stk.top() != nullptr && curr == nullptr) {
                        return false; 
                    }
                    stk.pop();
                }
                if (curr == nullptr)
                    continue;
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return true;
    }
};