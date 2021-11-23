/*
Number: 148
Topic: Sort List
Date: 2021/7/1
Rate: Medium
https://leetcode.com/problems/sort-list/

Given the head of a linked list, return the list after sorting it in ascending order.

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?


Constraints:
* The number of nodes in the list is in the range [0, 5 * 10^4].
* -10^5 <= Node.val <= 10^5

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
    ListNode* sortList(ListNode* head) {

        // tc: O(nlogN) ; sc: O(1);
        if (!head || !head->next)
            return head;

        // 計算長度，因為總共有 logN 層
        ListNode* lenNode = head;
        int len = 0;
        while (lenNode) {
            lenNode = lenNode->next;
            len++;
        }

        ListNode dummy(0, head);
        ListNode* left;
        ListNode* right;
        // logN 層，從最那面那層開始 merge
        for (int i = 1; i < len; i *= 2) {
            ListNode* toConnect = &dummy;
            // 第一輪的第一部分從 head 開始
            ListNode* start = toConnect->next;
            while (start) {
                left = start;
                right = getNode(left, i); // 拿到第二部分的開頭，順便斷開第一部分的鎖鏈
                start = getNode(right, i); // 拿到下一輪第一部分的開頭，順便斷開第二部分的鎖鏈，如果沒有下一輪了，會回傳 null，而第二部就直接開到底
                toConnect = merge(left, right, toConnect);
            }
        }
        return dummy.next;
    }

    ListNode* getNode(ListNode* head, int n) {
        // 把前面 n 個 Node 畫為一組(包含 head)，並且斷開最後一個 node 與後面 node 的連結
        // 回傳後面那部份的第一個 node
        for (int i = 1; i < n && head; i++) {
            head = head->next;
        }

        // 如果不足 n 個 node，或是剛好到底了，就回傳 null
        if (!head)
            return nullptr;
        // 回傳後面第一個 node
        ListNode* nextNode = head->next;
        // 斷開前面那部份的連結
        head->next = nullptr;

        return nextNode;
    }

    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* toConnect) {
        // merge 兩個部分的 node
        // 並且把他們連到前面的開頭
        ListNode* cur = toConnect;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        cur->next = (l1) ? l1 : l2;
        
        while (cur->next) {
            cur = cur->next;
        }
        // 回傳下一個部分的開頭

        return cur;
    }
};