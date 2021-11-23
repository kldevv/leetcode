/*
Number: 160
Topic: Intersection of Two Linked Lists
Date: 2021/6/30
Rate: Easy
https://leetcode.com/problems/intersection-of-two-linked-lists/

Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:


It is guaranteed that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

Constraints:
* The number of nodes of listA is in the m.
* The number of nodes of listB is in the n.
* 0 <= m, n <= 3 * 104
* 1 <= Node.val <= 105
* 0 <= skipA <= m
* 0 <= skipB <= n
* intersectVal is 0 if listA and listB do not intersect.
* intersectVal == listA[skipA + 1] == listB[skipB + 1] if listA and listB intersect.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // see post: https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49785/Java-solution-without-knowing-the-difference-in-len!
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        while (ptrA != ptrB) {
            ptrA = (ptrA == nullptr) ? headB : ptrA->next;
            ptrB = (ptrB == nullptr) ? headA : ptrB->next;
        }
        return ptrA;
    }
};