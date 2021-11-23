/*
Number: 203
Topic: Remove Linked List Elements
Date: 2021/6/29
Rate: Easy
https://leetcode.com/problems/remove-linked-list-elements/

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

Constraints:
* The number of nodes in the list is in the range [0, 104].
* 1 <= Node.val <= 50
* 0 <= val <= 50
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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) {
            head = head->next;
        }
        ListNode* node = head;
        
        while (node != nullptr && node->next != nullptr) {
            while (node->next != nullptr && node->next->val == val) {
                node->next = node->next->next;
            }
            node = node->next;
        }
        return head;
    }
};