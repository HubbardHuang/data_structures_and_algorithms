/*
Title: Invert Binary Tree

Description:
Invert a binary tree.

Example:
Input:
     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:
     4
   /   \
  7     2
 / \   / \
9   6 3   1
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
    void Invert(TreeNode* node) {
        if (!node) {
            return;
        }
        swap(node->left, node->right);
        Invert(node->left);
        Invert(node->right);
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        Invert(root);
        return root;
    }
};