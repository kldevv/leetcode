/*
Number: 273
Topic: Delete Node in a Linked List
Date: 2021/6/29
Rate: Easy
https://leetcode.com/problems/delete-node-in-a-linked-list/


Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list, instead you will be given access to the node to be deleted directly.

It is guaranteed that the node to be deleted is not a tail node in the list.

Constraints:
* The number of the nodes in the given list is in the range [2, 1000].
* -1000 <= Node.val <= 1000
* The value of each node in the list is unique.
* The node to be deleted is in the list and is not a tail node

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // 無法真的刪除這個 node，要做的事是把下一個 node 的值複製過來，然後刪除下一個 node
        // node->val = node->next->val 和 node->next = node->next->next
        ListNode* next = node->next;
        // deep copy
        *node = *next;
        delete next;
    }
};