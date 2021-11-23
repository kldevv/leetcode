/*
Number: 328
Topic: Odd Even Linked List
Date: 2021/6/25
Rate: Medium
https://leetcode.com/problems/odd-even-linked-list/


Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Constraints:
* n == number of nodes in the linked list
* 0 <= n <= 104
* -106 <= Node.val <= 106

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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        ListNode* node = head;
        ListNode* evenHead = head->next;
        ListNode* oddTail = head;
        int odd = true;

        while (node != nullptr) {
            ListNode* temp = node->next;
            // 連到下一個 odd 或 even
            if (node->next != nullptr)
                node->next = node->next->next;

            // 要知道 odd 的尾巴是什麼，才能跟 even 的頭接起來
            if (odd)
                oddTail = node;
            odd = !odd;

            // 每一個 node 都要這樣做！
            node = temp;
        }
        oddTail->next = evenHead;

        return head;
    }
};