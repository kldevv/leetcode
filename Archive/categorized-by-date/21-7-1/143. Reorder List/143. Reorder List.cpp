/*
Number: 143
Topic: Reorder List
Date: 2021/7/1
Rate: Medium
https://leetcode.com/problems/reorder-list/

You are given the head of a singly linked-list. The list can be represented as:

    L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

    L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.


Constraints:
* The number of nodes in the list is in the range [1, 5 * 104].
* 1 <= Node.val <= 1000

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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // 先找到中點
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 把後面的 list 反轉
        ListNode* rev = nullptr;
        while (slow) {
            ListNode* temp = slow->next;
            slow->next = rev;
            rev = slow;
            slow = temp;
        }
        // merge
        while (rev->next) {
            // temp
            ListNode* headNext = head->next;
            ListNode* revNext = rev->next;
            // 頭接尾
            head->next = rev;
            // 尾再接回頭
            head->next->next = headNext;
            // 兩個都跳到下一個
            head = headNext;
            rev = revNext;
        }
    }
};