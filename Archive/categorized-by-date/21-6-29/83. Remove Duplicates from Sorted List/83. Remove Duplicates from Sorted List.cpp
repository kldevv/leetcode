/*
Number: 83
Topic: Remove Duplicates from Sorted List
Date: 2021/6/29
Rate: Easy
https://leetcode.com/problems/remove-duplicates-from-sorted-list/

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* node = head;
        while (node != nullptr && node->next != nullptr) {
            // 刪除後面全部的重複的 node 
            while (node->next != nullptr && node->val == node->next->val) {
                node->next = node->next->next;
            }
            node = node->next;
        }
        return head;
    }
};