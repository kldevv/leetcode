/*
Number: 138
Topic: Copy List with Random Pointer
Date: 2021/11/18
Rate: Medium
https://leetcode.com/problems/copy-list-with-random-pointer/

A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
    * val: an integer representing Node.val
    * random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.

Your code will only be given the head of the original linked list.

Constraints:
    * 0 <= n <= 1000
    * -10000 <= Node.val <= 10000
    * Node.random is null or is pointing to some node in the linked list.
*/

#include <iostream>

using namespace std;

// /*
// Definition for a Node.
class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
// */

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        /* Store copy node immediately after the original node

        1. Copy node
            copy(node)->next = node->next
            node->next = copy(node)
        2. Assign random pointer
            copy(node)->random = node->random->next
        3. Restore the original list and get copy list
            temp = node->next
            node->next = node->next->next
            node = temp
        return head->next
        */
        // Edge case
        if (!head)
            return nullptr;

        // Copy node
        Node* node = head;
        while (node) {
            Node* copyNode = new Node(node->val);
            copyNode->next = node->next;
            node->next = copyNode;
            node = copyNode->next;
        }

        // Assign random pointer
        node = head;
        while (node) {
            node->next->random = (node->random) ? node->random->next : nullptr;
            node = node->next->next;
        }

        // Restore and Get
        node = head;
        Node* copyHead = node->next;
        Node* temp;
        while (node && node->next) {
            temp = node->next;
            node->next = node->next->next;
            node = temp;
        }
        return copyHead;
    }
};