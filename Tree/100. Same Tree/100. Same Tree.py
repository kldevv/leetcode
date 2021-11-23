'''
Number: 100
Topic: Same Tree
Date: 2021/10/15
Rate: Easy
https://leetcode.com/problems/same-tree/

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Constraints:
    * The number of nodes in both trees is in the range [0, 100].
    * -104 <= Node.val <= 104
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p == None and q == None:
            return True
        if (p == None) != (q == None):
            return False

        return p.val == q.val and self.isSameTree(p.right, q.right) and self.isSameTree(p.left, q.left)
