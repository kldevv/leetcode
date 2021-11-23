/*
Number: 21
Topic: Merge Two Sorted Lists
Date: 2021/6/30
Rate: Easy
https://leetcode.com/problems/merge-two-sorted-lists/

Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

Constraints:
* The number of nodes in both lists is in the range [0, 50].
* -100 <= Node.val <= 100
* Both l1 and l2 are sorted in non-decreasing order.

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode preHead(0);
        ListNode* ptr = &preHead;

        while (l1 && l2) { // 兩個都還有才做比較
            if (l1->val <= l2->val)
                ptr->next = l1, l1 = l1->next;
            else 
                ptr->next = l2, l2 = l2->next;
            ptr = ptr->next;
        }
        // 其中一個用完了，而另外一個還有剩，接下來的全部都接上剩下的
        ptr->next = (l1) ? l1 : l2;
        return preHead.next;
    }
};