/*
Title: Leaf-Similar Trees

Description:
Consider all the leaves of a binary tree.
From left to right order,
the values of those leaves form a leaf value sequence.
Two binary trees are considered leaf-similar
if their leaf value sequence is the same.
Return true if and only if
the two given trees with head nodes root1 and root2 are leaf-similar.

Note:
    Both of the given trees will have between 1 and 100 nodes.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void Preorder(TreeNode* root, vector<int>& buffer) {
        // if (!root) {
        //     return;
        // }
        // if (!root->left && !root->right) {
        //     buffer.push_back(root->val);
        // } else {
        //     Preorder(root->left, buffer);
        //     Preorder(root->right, buffer);
        // }
        stack<TreeNode*> node_stack;
        if (!root) {
            return;
        }
        node_stack.push(root);
        while (!node_stack.empty()) {
            auto curr = node_stack.top();
            node_stack.pop();
            if (!curr->left && !curr->right) {
                buffer.push_back(curr->val);
            } else {
                if (curr->left) {
                    node_stack.push(curr->left);
                }
                if (curr->right) {
                    node_stack.push(curr->right);
                }
            }
        }
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> buffer1;
        vector<int> buffer2;
        Preorder(root1, buffer1);
        Preorder(root2, buffer2);
        return buffer1 == buffer2;
    }
};