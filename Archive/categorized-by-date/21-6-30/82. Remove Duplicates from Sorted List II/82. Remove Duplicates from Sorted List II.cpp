/*
Number: 82
Topic: Remove Duplicates from Sorted List II
Date: 2021/6/30
Rate: Medium
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Constraints:
* The number of nodes in the list is in the range [0, 300].
* -100 <= Node.val <= 100
* The list is guaranteed to be sorted in ascending order.

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* node = dummy;
        while (node != nullptr && node->next != nullptr) {
            while (node->next != nullptr && node->next->next != nullptr && node->next->val == node->next->next->val) {
                int val = node->next->val;
                while (node->next != nullptr && node->next->val == val) {
                    node->next = node->next->next;
                }
            }
            node = node->next;
        }
        node = dummy->next;
        delete dummy;
        
        return node;
    }
};