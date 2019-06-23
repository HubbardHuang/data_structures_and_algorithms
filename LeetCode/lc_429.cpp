/*
Title: N-ary Tree Level Order Traversal

Description:
Given an n-ary tree,
return the level order traversal of its nodes' values.
(ie, from left to right, level by level).

Note:
    The depth of the tree is at most 1000.
    The total number of nodes is at most 5000.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<pair<Node*, int>> node_queue;
        if (!root) {
            return result;
        }
        node_queue.push({ root, 0 });
        int curr_level = 0;
        vector<int> buffer;
        while (!node_queue.empty()) {
            auto curr_node = node_queue.front();
            node_queue.pop();
            buffer.push_back(curr_node.first->val);
            for (auto kid : curr_node.first->children) {
                node_queue.push({ kid, curr_node.second + 1 });
            }
            if (!node_queue.empty() &&
                  node_queue.front().second != curr_node.second ||
                node_queue.empty()) {
                result.push_back(buffer);
                buffer.clear();
            }
        }
        return result;
    }
};