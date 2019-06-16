/*
Title: Univalued Binary Tree

Description:
A binary tree is univalued if every node in the tree has the same value.
Return true if and only if the given tree is univalued.

Example 1:
Input: [1,1,1,1,1,null,1]
Output: true

Example 2:
Input: [2,2,2,5,2]
Output: false

Note:
    The number of nodes in the given tree will be in the range [1, 100].
    Each node's value will be an integer in the range [0, 99].
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
    bool isUnivalTree(TreeNode* root) {
        /* Recursion */
        // if (!root) {
        //     return true;
        // }
        // if (root->left && root->val != root->left->val) {
        //     return false;
        // }
        // if (root->right && root->val != root->right->val) {
        //     return false;
        // }
        // return isUnivalTree(root->left) && isUnivalTree(root->right);

        /* Iteration */
        stack<TreeNode*> node_stack;
        if (!root) {
            return true;
        }
        int key = root->val;
        node_stack.push(root);
        while (!node_stack.empty()) {
            TreeNode* curr = node_stack.top();
            node_stack.pop();
            if (curr->val != key) {
                return false;
            }
            if (curr->left) {
                node_stack.push(curr->left);
            }
            if (curr->right) {
                node_stack.push(curr->right);
            }
        }
        return true;
    }
};