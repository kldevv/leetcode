/*
Number: 297
Topic: Serialize and Deserialize Binary Tree
Date: 2021/12/3
Rate: Hard
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Constraints:
    * The number of nodes in the tree is in the range [0, 104].
    * -1000 <= Node.val <= 1000
*/

#include <sstream>
#include <string>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream output;
        serialize(root, output);

        return output.str();
    }

    void serialize(TreeNode* root, stringstream& output) {
        if (root == nullptr) {
            output << "$"
                   << " " << endl;
            return;
        }
        output << to_string(root->val) << " ";
        serialize(root->left, output);
        serialize(root->right, output);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream input(data);
        return deserialize(input);
    }

    TreeNode* deserialize(stringstream& input) {
        string val;
        input >> val;
        if (val == "$")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(input);
        root->right = deserialize(input);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));