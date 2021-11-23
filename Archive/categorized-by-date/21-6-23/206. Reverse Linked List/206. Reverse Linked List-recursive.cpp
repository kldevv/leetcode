/*
Number: 206
Topic: Reverse Linked List
Date: 2021/6/23
Rate: Easy
https://leetcode.com/problems/reverse-linked-list/

Given the head of a singly linked list, reverse the list, and return the reversed list.

Constraints:
* The number of nodes in the list is the range [0, 5000].
* -5000 <= Node.val <= 5000

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

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
    // recursive method
    ListNode* reverseList(ListNode* head) {
        return reverseList(head, nullptr);
    }

    ListNode* reverseList(ListNode* head, ListNode* prev) {
        if (head == nullptr)
            return prev;
        ListNode* newHead = reverseList(head->next, head);
        head->next = prev;
        return newHead;
    }
};