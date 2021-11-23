/*
Number: 236
Topic: Lowest Common Ancestor of a Binary Tree
Date: 2021/6/16
Rate: Medium
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Constraints:
* The number of nodes in the tree is in the range [2, 105].
* -109 <= Node.val <= 109
* All Node.val are unique.
* p != q
* p and q will exist in the tree.

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* right = (root->right == nullptr) ? nullptr : lowestCommonAncestor(root->right, p, q);
        TreeNode* left = (root->left == nullptr) ? nullptr : lowestCommonAncestor(root->left, p, q);

        // 在任一個 node 只有三種可能
        // 1. 此 Node 是要找的，另一目標則是這個 Node 的小孩 -> 回傳這個 Node
        // 2. 此 Node 是要找的，但另一個目標不在這個 Node 的底下 -> 回傳這個 Node
        // 3. 此 Node 不是要找的，但是另一個目標分別在左右兩端 -> 回傳這個 Node
        // 4. 此 Node 不是要找的，但是從左邊或右邊找到一個或兩個目標 -> 傳遞有找到的答案 (找到一個目標為2.而往上會決定他們的相會點，這邊只要傳遞有找到的事實就好，也就是非 nullptr) (找到兩個目標則是 1.，此時拿到的就是答案了，一樣網上回傳)
        // 5. 此 Node 不是要找的，而左右的小孩也都沒找到 -> 回傳錯誤答案 Nullptr

        // 如果兩邊都是不是 nullptr 代表這邊是交界點，回傳
        if (right != nullptr && left != nullptr)
            return root;
        // 如果 root 是要找的值，就回傳 root
        if (root == p || root == q)
            return root;
        // 如只有一個不是 nullptr ，就回傳那個值，代表要找的兩個 node 都在那邊
        if (right != nullptr || left != nullptr)
            return (right == nullptr) ? left : right;
        
        // 兩個都是 null，代表以下的都是廢物，這個也可回傳 nullptr
        return nullptr;
    }
};