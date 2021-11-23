/*
Number: 92
Topic: Reverse Linked List II
Date: 2021/6/26
Rate: Medium
https://leetcode.com/problems/reverse-linked-list-ii/

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Constraints:
The number of nodes in the list is n.
* 1 <= n <= 500
* -500 <= Node.val <= 500
* 1 <= left <= right <= n

Follow up: Could you do it in one pass?

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // see post: https://leetcode.com/problems/reverse-linked-list-ii/discuss/30709/Talk-is-cheap-show-me-the-code-(and-DRAWING)

        ListNode* dummyNode = new ListNode(0, head);
        ListNode* preNode =  dummyNode;
        for (int i = 0; i < left-1; i++) {
            preNode = preNode->next;
        }

        ListNode* tailNode = preNode->next;

        for (int j = 0; j < right-left; j++) {
            ListNode* preNodeOriNext = preNode->next;
            preNode->next = tailNode->next;
            tailNode->next = tailNode->next->next;
            preNode->next->next = preNodeOriNext;
        }
        return dummyNode->next;
    }
};