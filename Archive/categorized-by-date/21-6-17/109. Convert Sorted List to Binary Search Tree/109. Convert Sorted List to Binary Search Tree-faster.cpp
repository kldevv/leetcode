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
        ListNode* iterator = head;
        int size = 0;
        while (iterator != nullptr) {
            iterator = iterator->next;
            size += 1;
        }
        return sortedListToBST(head, 0, size-1);
    }

    TreeNode* sortedListToBST(ListNode*& head, int left, int right) {
        // tc: O(n) sc: O(logN) because recursion stack
        // 用 left 和 right 來計算目前的 head 應該擺在哪裡，當作 left , right 之類的
        if (right < left)
            return nullptr;

        int mid = left + (right-left)/2;

        TreeNode* leftChild = sortedListToBST(head, left, mid-1);

        TreeNode* midPointRoot = new TreeNode(head->val);
        head = head->next;

        midPointRoot->left = leftChild;

        midPointRoot->right = sortedListToBST(head, mid+1, right);

        return midPointRoot;
    }
};