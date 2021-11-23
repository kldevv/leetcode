/*
Number: 222
Topic: Count Complete Tree Nodes
Date: 2021/6/18
Rate: Medium
https://leetcode.com/problems/count-complete-tree-nodes/


Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

Constraints:
* The number of nodes in the tree is in the range [0, 5 * 104].
* 0 <= Node.val <= 5 * 104
* The tree is guaranteed to be complete.

 
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
    int getHeight(TreeNode* root) {
        // 只用 traverse 左邊就可以拿到高
        // 高的計算方式是看有多少個 edge，或是不算 root ，有幾層的 Node
        // 空的樹高是 -1 
        // 只有 root 的高是 0
        return (root == nullptr) ? -1 : 1 + getHeight(root->left);
    }

    int countNodes(TreeNode* root) {
        int height = getHeight(root);

        // 如果是空的樹回傳 0
        // 如果右邊 subtree 的高等於左邊的減一，左邊的樹都被填滿了，才會讓右邊的 subtree 的高跟左邊的 subtree 的高e一樣，這時候左邊的 subtree + root 有 (2^height) - 1 + 1 個 node，右邊的 subtree 有多少 node，就 recursive call 就好
        // 如果右邊 subtree 的高不等於左邊的減一，左邊的樹沒被填滿，這時候右邊的 subtree + root 有 (2^(height-1)) - 1 + 1 個 node，左邊邊的 subtree 有多少 node，就 recursive call 就好
        
        // 計算高要話 O(logN) 而每一層都會 recursive call 下一層，總共會 call O(height) 次，所以 tc 總共是 O((logN)^2)
        return (height == -1) ? 0 : (getHeight(root->right) == height-1) ? (1 << height)+countNodes(root->right) : (1 << height-1)+countNodes(root->left);
    }
};