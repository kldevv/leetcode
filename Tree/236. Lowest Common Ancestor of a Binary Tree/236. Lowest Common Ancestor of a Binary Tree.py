'''
Number: 236
Topic: Lowest Common Ancestor of a Binary Tree
Date: 2021/10/15
Rate: Medium
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Constraints:
    * The number of nodes in the tree is in the range [2, 105].
    * -109 <= Node.val <= 109
    * All Node.val are unique.
    * p != q
    * p and q will exist in the tree.
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def findNode(root):
            if root == None:
                return (False, False, None)

            p_present_right, q_present_right, LCA_right = findNode(root.right)
            p_present_left, q_present_left, LCA_left = findNode(root.left)

            p_present = (p_present_left) or (p_present_right) or (root.val == p.val)
            q_present = (q_present_left) or (q_present_right) or (root.val == q.val)

            LCA = LCA_left or LCA_right
            if not LCA and p_present and q_present:
                LCA = root
            return (p_present, q_present, LCA)

        return findNode(root)[2]