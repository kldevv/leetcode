/*
Number: 116
Topic: Populating Next Right Pointers in Each Node
Date: 2021/6/18
Rate: Medium
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/


You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Follow up:

* You may only use constant extra space.
* Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem

Constraints:
* The number of nodes in the given tree is less than 4096.
* -1000 <= node.val <= 1000

 
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        connect(root, nullptr);
        return root;
    }

    void connect(Node* root, Node* otherSide) {
        if (root == nullptr)
            return;

        root->next = otherSide;

        // there is no next level
        if (root->left == nullptr)
            return;

        // recursive call
        connect(root->left, root->right);
        (otherSide != nullptr) ? connect(root->right, otherSide->left) : connect(root->right, nullptr);
    }

};