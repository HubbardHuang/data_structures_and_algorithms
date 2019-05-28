/*
Title: Convert BST to Greater Tree

Description:
Given a Binary Search Tree (BST),
convert it to a Greater Tree
such that every key of the original BST
is changed to the original key plus sum of all keys
greater than the original key in BST.

Example:
Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13
Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
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
    void InOrder(TreeNode* node, int& sum) {
        if (!node) {
            return;
        }
        if (node->right) {
            InOrder(node->right, sum);
        }
        sum += node->val;
        node->val += (sum - node->val);
        if (node->left) {
            InOrder(node->left, sum);
        }
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        InOrder(root, sum);
        return root;
    }
};