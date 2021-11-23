/*
Number: 147
Topic: Insertion Sort List
Date: 2021/7/2
Rate: Medium
https://leetcode.com/problems/insertion-sort-list/

Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

1. Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
2. At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
3. It repeats until no input elements remain.

The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.


Constraints:
* The number of nodes in the list is in the range [1, 5000].
* -5000 <= Node.val <= 5000

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0, nullptr);
        ListNode* cur = head;
        while (cur) {
            ListNode* sorted = &dummy;
            while (sorted->next && (sorted->next->val <= cur->val)) {
                sorted = sorted->next;
            }
            ListNode* sortNext = sorted->next;
            sorted->next = cur;
            ListNode* curNext = cur->next;
            cur->next = sortNext;

            cur = curNext;
        }
        return dummy.next;
    }
};