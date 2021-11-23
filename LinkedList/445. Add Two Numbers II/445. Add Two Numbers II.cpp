/*
Number: 445
Topic: Add Two Numbers II
Date: 2021/9/23
Rate: Medium
https://leetcode.com/problems/4sum-ii/

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Constraints:
    * The number of nodes in each linked list is in the range [1, 100].
    * 0 <= Node.val <= 9
    * It is guaranteed that the list represents a number that does not have leading zeros.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;

        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* nextNode = nullptr;
        ListNode* head = nullptr;
        int carry = 0;
        int digit = 0;
        while (s1.size() || s2.size() || carry) {
            int total = carry;
            if (s1.size()) {
                total += s1.top();
                s1.pop();
            }
            if (s2.size()) {
                total += s2.top();
                s2.pop();
            }

            digit = total % 10;
            carry = total / 10;
            
            head = new ListNode(digit, nextNode);
            nextNode = head;
        }
        return head;
    }
};