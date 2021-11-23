/*
Number: 117
Topic: Populating Next Right Pointers in Each Node II
Date: 2021/6/19
Rate: Medium
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

Given a binary tree

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
* Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.

Constraints:
* The number of nodes in the given tree is less than 6000.
* -100 <= node.val <= 100

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

        // 如果 otherSide 沒有 children，這邊的 otherSide，就要再往右邊看去那一層，一直到有 child 或是變成 null
        while (otherSide != nullptr && otherSide->right == nullptr && otherSide->left == nullptr)
            otherSide = otherSide->next;

        // 有 right 的話 right +  otherSide->(left or right)； left -> right
        if (root->right != nullptr) {
            if (otherSide == nullptr)
                connect(root->right, nullptr);
            else
                (otherSide->left != nullptr) ? connect(root->right, otherSide->left) : connect(root->right, otherSide->right);
            // 注意 right 要先建立起來，不然 left recurse 到底結果上面的 next 都還沒建立起來 ><，第一個迴圈就沒用了
            connect(root->left, root->right);
        // 沒有 right 話，left +  otherSide->(left or right)
        } else {
            if (otherSide == nullptr)
                connect(root->left, nullptr);
            else
                (otherSide->left != nullptr) ? connect(root->left, otherSide->left) : connect(root->left, otherSide->right);            
        }
    }
};