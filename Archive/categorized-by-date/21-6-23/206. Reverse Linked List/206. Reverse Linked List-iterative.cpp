/*
Number: 206
Topic: Reverse Linked List
Date: 2021/6/23
Rate: Easy
https://leetcode.com/problems/reverse-linked-list/

Given the head of a singly linked list, reverse the list, and return the reversed list.

Constraints:
* The number of nodes in the list is the range [0, 5000].
* -5000 <= Node.val <= 5000

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

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
    // recursive method
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            // 先把下一個存起來
            ListNode* temp = head->next;
            // 這個的下一個改成上一個
            head->next = prev;
            // 上一個改成這一個
            prev = head;
            // 這個的下一個改成這一個
            head = temp;
        }
        return prev;
    }
};