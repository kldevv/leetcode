/*
Number: 369
Topic: Plus One Linked List
Date: 2021/7/21
Rate: Medium
https://leetcode.com/problems/plus-one-linked-list/

Given a non-negative integer represented as a linked list of digits, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list.

Constraints:
* The number of nodes in the linked list is in the range [1, 100].
* 0 <= Node.val <= 9
* The number represented by the linked list does not contain leading zeros except for the zero itself. 
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
    ListNode* plusOne(ListNode* head) {
        plusOne(head, nullptr);
        if (head->val > 9) {
            head->val = 0;
            ListNode* temp = new ListNode(1, head);
            head = temp;
        }
        return head;
    }

    void plusOne(ListNode* head, ListNode* prev) {
        if (head->next == nullptr) {
            head->val += 1;
            return;
        }

        plusOne(head->next, head);
        if (head->next->val > 9) {
            head->next->val = 0;
            head->val += 1;
        }
    }
};