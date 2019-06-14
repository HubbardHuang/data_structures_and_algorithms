/*
Title: N-ary Tree Preorder Traversal

Description:
Given an n-ary tree,
return the preorder traversal of its nodes' values.

Note:
Recursive solution is trivial,
could you do it iteratively?
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
    vector<int> preorder(Node* root) {
        if (!root) {
            return {};
        }
        vector<int> result;
        stack<Node*> node_stack;
        node_stack.push(root);
        while (!node_stack.empty()) {
            Node* curr = node_stack.top();
            node_stack.pop();
            result.push_back(curr->val);
            for (int i = curr->children.size() - 1; i >= 0; i--) {
                node_stack.push(curr->children[i]);
            }
        }
        return result;
    }
};