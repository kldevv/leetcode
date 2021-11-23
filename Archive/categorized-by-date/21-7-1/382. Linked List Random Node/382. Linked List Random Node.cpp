/*
Number: 382
Topic: Linked List Random Node
Date: 2021/7/1
Rate: Medium
https://leetcode.com/problems/linked-list-random-node/

GGiven a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Constraints:
* The number of nodes in the linked list will be in the range [1, 10^4].
* -10^4 <= Node.val <= 10^4
* At most 10^4 calls will be made to getRandom.

Follow up:
* What if the linked list is extremely large and its length is unknown to you?
* Could you solve this efficiently without using extra space?

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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* head;
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int count = 1;
        int result = head->val;
        ListNode* cur = head->next;

        while (cur) {  
            if (!(rand() % ++count))
                result = cur->val;
            cur = cur->next;
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */