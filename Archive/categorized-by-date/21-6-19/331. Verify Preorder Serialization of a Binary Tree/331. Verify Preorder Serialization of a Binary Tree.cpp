/*
Number: 331
Topic: Verify Preorder Serialization of a Binary Tree
Date: 2021/6/19
Rate: Medium
https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

One way to serialize a binary tree is to use preorder traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as '#'.

For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where '#' represents a null node.

Given a string of comma-separated values preorder, return true if it is a correct preorder traversal serialization of a binary tree.

It is guaranteed that each comma-separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid.

    * For example, it could never contain two consecutive commas, such as "1,,3".

Note: You are not allowed to reconstruct the tree.

Constraints:
* 1 <= preorder.length <= 104
* preoder consist of integers in the range [0, 100] and '#' separated by commas ','.

*/

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
    bool isValidSerialization(string preorder) {
        
        vector<string> split;
        string temp;

        // split by ','
        for (char c : preorder) {
            if (c == ',') {
                split.push_back(temp);
                temp = "";
                continue;
            }
            temp += c;
        }
        split.push_back(temp);

        // if we think of null as the leaves in a binary tree, we have a rules that says leaves(the last layer) = non-leaves+1(all the layers above)
        int nonleaves = 0, leaves = 0;
        for (string s : split) {
            // if we have close the tree before we iterate all the nodes, it has more nodes than a binary tree should have.
            if (nonleaves+1 == leaves)
                return false;

            // consider it a leaves
            if (s == "#")
                leaves += 1;
            // whatever else is a node
            else
                nonleaves += 1;
        }
        return (nonleaves+1 == leaves);
        
    }
};