// 2022/01/02
#include <sstream>
using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream stream;
        serialize(root, stream);;
        return stream.str();
    }

    void serialize(TreeNode* root, stringstream& stream) {
        if (root == nullptr) {
            stream << "#" << " ";
            return;
        }
        stream << to_string(root->val) << " ";
        serialize(root->left, stream);
        serialize(root->right, stream);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream stream(data);
        return deserialize(stream);
    }

    TreeNode* deserialize(stringstream& stream) {
        string val;
        stream >> val;
        if (val == "#") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(stream);
        root->right = deserialize(stream);
        return root;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));