/*
Title: N-ary Tree Postorder Traversal

Description:
Given an n-ary tree,
return the postorder traversal of its nodes' values.

Note:
Recursive solution is trivial, could you do it iteratively?
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
private:
    void PostorderHelper(Node* root, vector<int>& buffer) {
        if (!root) {
            return;
        }
        for (auto n : root->children) {
            PostorderHelper(n, buffer);
        }
        buffer.push_back(root->val);
    }

public:
    vector<int> postorder(Node* root) {
        /* Recursion */
        // vector<int> result;
        // PostorderHelper(root, result);
        // return result;

        /* Iteration */
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
            for (int i = 0; i < curr->children.size(); i++) {
                node_stack.push(curr->children[i]);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};