'''
Number: 114
Topic: Flatten Binary Tree to Linked List
Date: 2021/10/15
Rate: Medium
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

Given the root of a binary tree, flatten the tree into a "linked list":
* The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
* The "linked list" should be in the same order as a pre-order traversal of the binary tree.

Constraints:
    * The number of nodes in the tree is in the range [0, 2000].
    * -100 <= Node.val <= 100

Follow up: Can you flatten the tree in-place (with O(1) extra space)?
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        def flatten_and_get_tail(root):
            if not root:
                return None

            if not root.left and not root.right:
                return root

            left_tail = flatten_and_get_tail(root.left)
            right_tail = flatten_and_get_tail(root.right)

            if left_tail: 
                left_tail.right = root.right
                root.right = root.left
                root.left = None


            return right_tail if right_tail else left_tail

        flatten_and_get_tail(root)
    

