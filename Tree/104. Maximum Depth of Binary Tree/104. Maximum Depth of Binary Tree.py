'''
Number: 104
Topic: Maximum Depth of Binary Tree
Date: 2021/10/15
Rate: Easy
https://leetcode.com/problems/maximum-depth-of-binary-tree/

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Constraints:
    * The number of nodes in the tree is in the range [0, 104].
    * -100 <= Node.val <= 100
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        def countDepth(root, curCount):
            if root == None:
                return curCount
            curCount += 1
            countRight = countDepth(root.right, curCount)
            countLeft = countDepth(root.left, curCount)
            return max(countLeft, countRight)
        return countDepth(root, 0)

