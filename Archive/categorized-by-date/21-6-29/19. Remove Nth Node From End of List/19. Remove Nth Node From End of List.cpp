/*
Number: 19
Topic: Remove Nth Node From End of List
Date: 2021/6/29
Rate: Medium
https://leetcode.com/problems/remove-nth-node-from-end-of-list/


Given the head of a linked list, remove the nth node from the end of the list and return its head.

Constraints:
* The number of nodes in the list is sz.
* 1 <= sz <= 30
* 0 <= Node.val <= 100
* 1 <= n <= sz

Follow up: Could you do this in one pass?

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        remove(dummy, n);

        return dummy->next;
    }

    void remove(ListNode* head, int& n) {
        if (head->next == nullptr) {
            n -= 1;
            return;
        }
        else {
            remove(head->next, n);
        }

        if (n == 0)
            head->next = head->next->next;
        n -= 1;
    }
};