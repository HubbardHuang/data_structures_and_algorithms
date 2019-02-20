/*
Title: Maximum Depth of N-ary Tree

Description:
Given a n-ary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path
from the root node down to the farthest leaf node.
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
    int maxDepth(Node* root) {
        if (!root) {
            return 0;
        }
        int max_depth = 0;
        for (int i = 0; i < root->children.size(); i++) {
            int depth = maxDepth(root->children[i]);
            if (depth > max_depth) {
                max_depth = depth;
            }
        }
        return 1 + max_depth;
    }
};