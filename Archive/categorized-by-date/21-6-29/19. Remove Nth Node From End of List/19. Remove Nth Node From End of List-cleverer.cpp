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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fastNode = head;
        ListNode* slowNode = head;
        
        // 確保 fastNode 在 slowNode 前面 N 個 Node
        for (int i = 0; i < n; i++) {
            fastNode = fastNode->next;
        }

        // 特別處理刪除的是 head 時
        if (fastNode == nullptr)
            return head->next;

        while (fastNode->next != nullptr) {
            fastNode = fastNode->next;
            slowNode = slowNode->next;
        }

        // slowNode 後面那個是要被刪除的
        slowNode->next = slowNode->next->next;
        return head;
    }
};