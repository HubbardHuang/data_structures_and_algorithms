/*
Title: Balanced Binary Tree

Description:
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:
a binary tree in which the depth of the two subtrees of every node never differ by more
than 1.

Example 1:
Given the following tree [3,9,20,null,null,15,7]:
    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:
Given the following tree [1,2,2,3,3,null,null,4,4]:
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
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
    int GetHeight(TreeNode* node) {
        if (!node) {
            return 0;
        }
        int left_height = GetHeight(node->left);
        int right_height = GetHeight(node->right);
        if (left_height != -1 && right_height != -1 &&
            abs(left_height - right_height) <= 1) {
            return 1 + max(left_height, right_height);
        } else {
            return -1;
        }
    }

public:
    bool isBalanced(TreeNode* root) { return GetHeight(root) != -1; }
};