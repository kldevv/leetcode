/*
Number: 61
Topic: Rotate List
Date: 2021/7/1
Rate: Medium
https://leetcode.com/problems/rotate-list/

Given the head of a linked list, rotate the list to the right by k places.

Constraints:
* The number of nodes in the list is in the range [0, 500].
* -100 <= Node.val <= 100
* 0 <= k <= 2 * 10^9

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
    ListNode* rotateRight(ListNode* head, int k) {
        // edge case
        if (!head || !head->next)
            return head;

        // 因為旋轉 len 次時等於回到原點，所先計算長度，再看看實際上到底只要 shift 幾次
        ListNode* lenNode = head;
        int shift = 0;
        while (lenNode) {
            lenNode = lenNode->next;
            shift += 1;
        }
        shift = k % shift;

        // shift 0 次等於沒動
        if (!shift)
            return head;

        // 當 fast 是最後一個 node 時
        // slow 剛好是倒數第 N+1 個 Node，也就是 shift 完後的尾巴
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < shift; i++) {
            fast = fast->next;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        // 最後一個 node 要接上頭
        fast->next = head;
        // slow 後面那個 node 就是倒數第 N 個 Node，也就是新的頭
        ListNode* newHead = slow->next;
        // slow 是最後一個 node
        slow->next = nullptr;

        return newHead;
    }
};