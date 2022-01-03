// 2022/01/03

class Solution {
private:
    vector<int> _preorder;
    vector<int> _inorder;
    unordered_map<int, int> _inorderPos;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        _preorder = preorder;
        _inorder = inorder;
        for (int i = 0; i < inorder.size(); i++) {
            _inorderPos[inorder[i]] = i;
        }
        int preorderPos = 0;
        return buildTree(0, inorder.size(), orderPos);
    }

    TreeNode* buildTree(int start, int end, int& preorderPos) {
        if (start >= end) {
            return nullptr;
        }
        int val = _preorder[preorderPos++];
        TreeNode* left = buildTree(start, _inorderPos[val], preorderPos);
        TreeNode* right = buildTree(_inorderPos[val]+1, end, preorderPos);
        return new TreeNode(val, left, right);
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