/*
Number: 25
Topic: Reverse Nodes in k-Group
Date: 2021/7/1
Rate: Hard
https://leetcode.com/problems/reverse-nodes-in-k-group/

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.


Follow-up: Can you solve the problem in O(1) extra memory space?

Constraints:
* The number of nodes in the list is in the range sz.
* 1 <= sz <= 5000
* 0 <= Node.val <= 1000
* 1 <= k <= sz

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);

        // 計算總共要 reverse 幾次
        ListNode* lenNode = head;
        int pack = 0;
        while (lenNode) {
            lenNode = lenNode->next;
            pack += 1;
        }
        pack /= k;

        ListNode* tail = &dummy;
        ListNode* temp;
        // 開始反轉
        for (int i = 0; i < pack; i++) {
            ListNode* rev = nullptr;
            ListNode* cur = head;
            // 反轉這次的 node
            for (int j = 0; j < k; j++) {
                temp = cur->next;
                cur->next = rev;
                rev = cur;
                cur = temp;
            }
            // 重點！上一個 tail 接續是這次反轉完後的最後一個 rev
            tail->next = rev;
            // 新的 tail 會變成這次反轉的頭，也就是反轉完後的最後一個 node
            tail = head;
            // 這一輪結束了，從下一個 node 開始重新再來一次
            head = temp;
        }
        // 後面剩下的不到 K 個的，直接接上去
        tail->next = temp;

        return dummy.next;
    }
};