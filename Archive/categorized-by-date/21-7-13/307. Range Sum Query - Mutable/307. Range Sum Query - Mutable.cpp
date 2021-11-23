/*
Number: 307
Topic: Range Sum Query - Mutable
Date: 2021/7/13
Rate: Medium
https://leetcode.com/problems/range-sum-query-mutable/

Given an integer array nums, handle multiple queries of the following types:

1. Update the value of an element in nums.
2. Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.

Implement the NumArray class:
* NumArray(int[] nums) Initializes the object with the integer array nums.
* void update(int index, int val) Updates the value of nums[index] to be val.
* int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

Constraints:
* 1 <= nums.length <= 3 * 104
* -100 <= nums[i] <= 100
* 0 <= index < nums.length
* -100 <= val <= 100
* 0 <= left <= right < nums.length
* At most 3 * 104 calls will be made to update and sumRange.
*/

struct SegmentTreeNode {
    int start;
    int end;
    int sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int start, int end) : start(start), end(end), sum(0), left(nullptr), right(nullptr) {}
};

class SegmentTree {
private:
    SegmentTreeNode* root;
    SegmentTreeNode* buildTree(vector<int>& nums, int i, int j) {
        if (i > j)
            return nullptr;

        SegmentTreeNode* root = new SegmentTreeNode(i, j);
        if (i == j) {
            root->sum = nums[i];
        }
        else {
            int m = i + (j-i)/2;
            root->left = buildTree(nums, i, m);
            root->right = buildTree(nums, m+1, j);
            root->sum = root->left->sum + root->right->sum;
        }
        return root;
    }

    void updateVal(SegmentTreeNode* root, int idx, int val) {
        if (root->start == root->end) {
            root->sum = val;
            return;
        }

        int i = root->start, j = root->end;
        int m = i + (j-i)/2;
        if (idx <= m)
            updateVal(root->left, idx, val);
        else
            updateVal(root->right, idx, val);
        root->sum = root->left->sum + root->right->sum;
    }

    int getRangeSum(SegmentTreeNode* root, int start, int end) {
        int i = root->start, j = root->end;

        if (i == start && j == end)
            return root->sum;

        int m = i + (j-i)/2;
        if (end <= m)
            return getRangeSum(root->left, start, end);
        if (start > m)
            return getRangeSum(root->right, start, end);
        return getRangeSum(root->left, start, m) + getRangeSum(root->right, m+1, end);
    }



public:
    SegmentTree(vector<int>& nums) {
        this->root = buildTree(nums, 0, nums.size()-1);
    }

    void updateVal(int idx, int val) {
        updateVal(this->root, idx, val);
    }

    int getRangeSum(int i, int j) {
        return getRangeSum(this->root, i, j);
    }
};


class NumArray {
private:
    SegmentTree* tree;
public:
    NumArray(vector<int>& nums) {
        tree = new SegmentTree(nums);
    }
    
    void update(int index, int val) {
        tree->updateVal(index, val);
    }
    
    int sumRange(int left, int right) {
        return tree->getRangeSum(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */