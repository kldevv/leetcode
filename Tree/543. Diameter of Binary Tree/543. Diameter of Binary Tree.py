'''
Number: 543
Topic: Diameter of Binary Tree
Date: 2021/10/15
Rate: Easy
https://leetcode.com/problems/diameter-of-binary-tree/

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

Constraints:
    * The number of nodes in the tree is in the range [1, 104].
    * -100 <= Node.val <= 100
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def maxDiameter(root):
            if root == None:
                return (0, 0)

            leftDepth, leftDia = maxDiameter(root.left)
            rightDepth, rightDia = maxDiameter(root.right)

            maxDia = max(max(leftDia, rightDia), rightDepth+leftDepth)
            # print(root.val, maxDia)
            return (max(leftDepth, rightDepth)+1, maxDia)

        return maxDiameter(root)[1]

