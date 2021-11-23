/*
Number: 86
Topic: Partition List
Date: 2021/7/2
Rate: Medium
https://leetcode.com/problems/partition-list/

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Constraints:
* The number of nodes in the list is in the range [0, 200].
* -100 <= Node.val <= 100
* -200 <= x <= 200

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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(0, head);
        ListNode dummy2(0, head);
        ListNode* p1 = &dummy1;
        ListNode* p2 = &dummy2;

        while (head) {
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
            } else {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }

        p2->next = nullptr;
        p1->next = dummy2.next;
        return dummy1.next;
    }
};
