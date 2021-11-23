/*
Number: 103
Topic: Binary Tree Zigzag Level Order Traversal
Date: 2021/6/16
Rate: Medium
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/


Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Constraints:
* The number of nodes in the tree is in the range [0, 2000].
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};

        int batchSize;
        bool toggle = true;
        TreeNode* currNode;
        deque<TreeNode*> dq;
        vector<vector<int>> out;
        vector<int> temp;

        dq.push_back(root);

        while (!dq.empty()) {
            // use deque and switch between stack and queue
            batchSize = dq.size();
            for (int i = 0; i < batchSize; i++) {
                if (toggle) {
                    // 左到右輸出，用 queue 方式
                    currNode = dq.front();
                    dq.pop_front();

                    // pop front 時，要 push back 才不會干擾到
                    // 最左邊到時候是最後出來，所以先 push
                    if (currNode->left != nullptr) 
                        dq.push_back(currNode->left);
                    if (currNode->right != nullptr)
                        dq.push_back(currNode->right);
                } else {
                    // 右到左輸出，用 stack 方式
                    currNode = dq.back();
                    dq.pop_back();

                    // pop back 時，要 push front 才不會干擾到
                    // 最右邊最後出來，所以先 push
                    if (currNode->right != nullptr)
                        dq.push_front(currNode->right);
                    if (currNode->left != nullptr)
                        dq.push_front(currNode->left);
                }
                temp.push_back(currNode->val);
            }
            out.push_back(temp);
            temp.clear();
            toggle = !toggle;
        }
        return out;
    }
};