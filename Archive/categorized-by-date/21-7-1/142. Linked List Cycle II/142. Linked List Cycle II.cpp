/*
Number: 142
Topic: Linked List Cycle II
Date: 2021/7/1
Rate: Medium
https://leetcode.com/problems/linked-list-cycle-ii/

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Notice that you should not modify the linked list.


Constraints:
* The number of the nodes in the list is in the range [0, 10^4].
* -10^5 <= Node.val <= 10^5
* pos is -1 or a valid index in the linked-list.

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
    ListNode *detectCycle(ListNode *head) {
        // slow 和 fast 碰面的點，距離 cycle 開始的點的長度，跟 head 距離 cycle 開始的點的長度一樣。
        // see post: https://leetcode.com/problems/linked-list-cycle-ii/discuss/44781/Concise-O(n)-solution-by-using-C%2B%2B-with-Detailed-Alogrithm-Description
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* entry = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }
        return nullptr;
    }
};