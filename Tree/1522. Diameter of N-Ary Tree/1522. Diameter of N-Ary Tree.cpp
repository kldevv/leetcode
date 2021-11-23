/*
Number: 1522
Topic: Diameter of N-Ary Tree
Date: 2021/10/15
Rate: Medium
https://leetcode.com/problems/diameter-of-n-ary-tree/

Given a root of an N-ary tree, you need to compute the length of the diameter of the tree.

The diameter of an N-ary tree is the length of the longest path between any two nodes in the tree. This path may or may not pass through the root.

(Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value.)

Constraints:
    * The depth of the n-ary tree is less than or equal to 1000.
    * The total number of nodes is between [1, 104].
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int diameter(Node* root) {
        int result = 0;
        maxDiameter(root, result);
        return result;
    }

    int maxDiameter(Node* root, int& maxLen) {
        if (!root)
            return 0;

        int curMax = 0;
        int curSec = 0;
        for (Node* child : root->children) {
            int childLen = maxDiameter(child, maxLen);
            if (childLen > curMax) {
                curSec = curMax;
                curMax = childLen;
            } else if (childLen > curSec) {
                curSec = childLen;
            }
        }
        maxLen = max(maxLen, curMax+curSec);
        return curMax + 1;
    }
};
