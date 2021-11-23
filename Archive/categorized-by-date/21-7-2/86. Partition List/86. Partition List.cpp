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
        ListNode dummy(0, head);
        ListNode* p1 = &dummy;
        ListNode* cur = &dummy;

        // 先跳過前面全部小於 x 的 node
        while (p1 && p1->next && p1->next->val < x) {
            p1 = p1->next;
            cur = cur->next;
        }
        // 這時 p1->next 會大於 x
        // 接著繼續找，遇到小於 x 的，就把他 switch 到 p1 的下一個
        // 原本的位置則直接接著下一個 node
        while (cur && cur->next) {
            while (cur && cur->next && cur->next->val < x) {
                ListNode* temp = p1->next;
                p1->next = cur->next;

                cur->next = cur->next->next;
                p1->next->next = temp;

                p1 = p1->next;
            } 
            cur = cur->next;
        }
        return dummy.next;
    }
};
