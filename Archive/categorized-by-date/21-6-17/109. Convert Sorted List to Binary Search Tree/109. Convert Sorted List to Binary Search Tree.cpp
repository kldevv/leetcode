/*
Number: 109
Topic: Convert Sorted List to Binary Search Tree
Date: 2021/6/17
Rate: Medium
https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/


Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Constraints:
* The number of nodes in head is in the range [0, 2 * 104].
* -10^5 <= Node.val <= 10^5

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, nullptr);
        
    }

    TreeNode* sortedListToBST(ListNode* head, ListNode* tail) {
        if (head == tail)
            return nullptr;

        // if (head->next == nullptr)
        //     return new TreeNode(head->val);

        ListNode* oneStep = head;
        ListNode* twoStep = head;
        // 找中點，基數時會停在中點，偶數時會停在中點靠右
        while (twoStep != tail && twoStep->next != tail) {
            oneStep = oneStep->next;
            twoStep = twoStep->next->next;
        }

        TreeNode* midPointRoot = new TreeNode(oneStep->val);
        midPointRoot->right = sortedListToBST(oneStep->next, tail);
        midPointRoot->left = sortedListToBST(head, oneStep);

        return midPointRoot;
    }
};