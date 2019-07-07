/*
Title: Diameter of Binary Tree

Description:
Given a binary tree,
you need to compute the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path
between any two nodes in a tree.
This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note:
The length of path between two nodes
is represented by the number of edges between them.
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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int path = GetDepth(root->left) + GetDepth(root->right);
        int left_path = diameterOfBinaryTree(root->left);
        int right_path = diameterOfBinaryTree(root->right);
        return max(max(left_path, right_path), path);
    }

private:
    int GetDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left_depth = GetDepth(root->left);
        int right_depth = GetDepth(root->right);
        return 1 + (left_depth > right_depth ? left_depth : right_depth);
    }
};