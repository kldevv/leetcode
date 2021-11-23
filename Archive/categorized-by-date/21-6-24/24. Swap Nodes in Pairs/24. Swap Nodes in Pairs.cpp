/*
Number: 24
Topic: Swap Nodes in Pairs
Date: 2021/6/24
Rate: Medium
https://leetcode.com/problems/swap-nodes-in-pairs/

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)


Constraints:
* The number of nodes in the list is in the range [0, 100].
* 0 <= Node.val <= 100

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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;
        ListNode* newHead = head->next;

        while (head != nullptr && head->next != nullptr) {
            // 先記住第三個 node
            ListNode* temp = head->next->next;
            // 讓第二個 node 指向第一個 node
            head->next->next = head;
            // 第一個 node 指向第四個 node(如果有第四個 node) 或第三個 node
            if (temp != nullptr && temp->next != nullptr)
                head->next = temp->next;
            else 
                head->next = temp;
            // head 換成第三個 node
            head = temp;
        }
        return newHead;
    }
};