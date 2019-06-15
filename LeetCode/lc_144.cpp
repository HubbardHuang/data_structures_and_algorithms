/*
Title: Binary Tree Preorder Traversal

Description:
Given a binary tree,
return the preorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3
Output: [1,2,3]

Follow up: Recursive solution is trivial, could you do it iteratively?
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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> result;
        stack<TreeNode*> node_stack;
        node_stack.push(root);
        while (!node_stack.empty()) {
            TreeNode* curr = node_stack.top();
            node_stack.pop();
            if (curr->right) {
                node_stack.push(curr->right);
            }
            result.push_back(curr->val);
            if (curr->left) {
                node_stack.push(curr->left);
            }
        }
        return result;
    }
};