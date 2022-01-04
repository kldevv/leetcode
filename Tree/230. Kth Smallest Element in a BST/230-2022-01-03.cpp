// 2022/1/3

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int result;
        kthSmallest(root, k, result);
        return result;
    }
    void kthSmallest(TreeNode* root, int& k, int& result) {
        if (root == nullptr)
            return;
        
        kthSmallest(root->left, k, result);
        
        if (--k == 0) {
            result = root->val;
        }
        kthSmallest(root->right, k, result);
    }
};

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