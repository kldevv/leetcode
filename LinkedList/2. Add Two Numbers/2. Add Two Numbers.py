'''
Number: 2
Topic: Add Two Numbers II
Date: 2021/9/23
Rate: Medium
https://leetcode.com/problems/add-two-numbers/

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Constraints:
    * The number of nodes in each linked list is in the range [1, 100].
    * 0 <= Node.val <= 9
    * It is guaranteed that the list represents a number that does not have leading zeros.
'''

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy_head = ListNode(0, None)
        iterator = dummy_head
        carry = 0

        while l1 or l2 or carry:
            next_node = ListNode(0, None)
            iterator.next = next_node
            iterator = iterator.next

            sum_ = carry
            if l1:
                sum_ += l1.val
            if l2:
                sum_ += l2.val

            iterator.val = sum_ % 10
            carry = sum_ / 10

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        return dummy_head.next
