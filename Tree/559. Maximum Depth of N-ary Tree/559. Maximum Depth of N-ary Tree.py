'''
Number: 559
Topic: Maximum Depth of N-ary Tree
Date: 2021/10/15
Rate: Easy
https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

Constraints:
    * The total number of nodes is in the range [0, 104].
    * The depth of the n-ary tree is less than or equal to 1000.
'''

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        def countMaxDepth(root, curCount):
            if root == None:
                return curCount
            if len(root.children) == 0:
                return curCount+1

            curCount += 1
            result = 0
            for child in root.children:
                result = max(countMaxDepth(child, curCount), result)

            return result

        return countMaxDepth(root, 0)
