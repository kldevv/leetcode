/*
Number: 234
Topic: Palindrome Linked List
Date: 2021/6/30
Rate: Easy
https://leetcode.com/problems/palindrome-linked-list/

Given the head of a singly linked list, return true if it is a palindrome.

Follow up: Could you do it in O(n) time and O(1) space?

Constraints:
* The number of nodes in the list is in the range [1, 105].
* 0 <= Node.val <= 9

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
    bool isPalindrome(ListNode* head) {
        ListNode* revNode = nullptr;
        ListNode* slowNode = head;
        ListNode* fastNode = head;

        // node 的數量是奇數時， fast 會跑到最後一個 node， slow 會跑到中間那個
        while (fastNode && fastNode->next) {
            fastNode = fastNode->next->next;

            // 把前面的 node 反轉，rev 就是一個往前走的 LinkedList
            ListNode* temp = revNode;
            revNode = slowNode;
            slowNode = slowNode->next;
            revNode->next = temp;
        }

        // node 的數量是奇數時， fast 會跑到最後一個 node， slow 會跑到中間那個
        // 因為我們不在乎中間那個，所以讓 slow 往後走一個
        if (fastNode)
            slowNode = slowNode->next;

        // 讓 slow 跟 rev 開始往前後跑，如果都一樣，就會一起走到 nullptr
        // 如果要讓 LinkedList 不改變，在這個地方把前面的 LinkedList 反轉回來就行了
        while (revNode && (slowNode->val == revNode->val)) {
            revNode = revNode->next;
            slowNode = slowNode->next;
        }
        return (!revNode);
    }
};