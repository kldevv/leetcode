/*
Number: 133
Topic: Clone Graph
Date: 2021/7/5
Rate: Medium
https://leetcode.com/problems/clone-graph/

Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.



Constraints:
* The number of nodes in the graph is in the range [0, 100].
* 1 <= Node.val <= 100
* Node.val is unique for each node.
* There are no repeated edges and no self-loops in the graph.
* The Graph is connected and all nodes can be visited starting from the given node.

*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        // BFS
        // traverse 所有的 node，用 umap 記錄舊到新的 node，然後 traverse 每個舊的 node 的 neighbors 把它加進新的 node 的 neighbors
        // 只有遇到沒有生成過新的 node 時才新增新的 node

        queue<Node*> q;
        // 舊到新的 mapping
        unordered_map<Node*, Node*> umap;
        umap[node] = new Node(node->val);

        q.push(node);
        while (!q.empty()) {
            Node* curNode = q.front();
            q.pop();
            for (Node* neighbor : curNode->neighbors) {
                if (!umap.count(neighbor)) {
                    umap[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                umap[curNode]->neighbors.push_back(umap[neighbor]);
            }
        }

        return umap[node];
    }
};