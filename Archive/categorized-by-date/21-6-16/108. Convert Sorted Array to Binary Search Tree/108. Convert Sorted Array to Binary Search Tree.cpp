/*
Number: 108
Topic: Convert Sorted Array to Binary Search Tree
Date: 2021/6/16
Rate: Easy
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Constraints:
* 1 <= nums.length <= 10^4
* -10^4 <= nums[i] <= 10^4
* nums is sorted in a strictly increasing order.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums, int i, int j) {
        if (j < i)
            return nullptr;

        int m = i + (j-i)/2;

        TreeNode* out = new TreeNode(nums[m]);
        out->right = sortedArrayToBST(nums, m+1, j);
        out->left = sortedArrayToBST(nums, i, m-1);

        return out;
    }
};