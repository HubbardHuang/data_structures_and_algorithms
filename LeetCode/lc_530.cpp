/*
Title: Minimum Absolute Difference in BST

Description:
Given a binary search tree with non-negative values,
find the minimum absolute difference between values of any two nodes.

Example:
Input:
   1
    \
     3
    /
   2
Output:
1

Explanation:
The minimum absolute difference is 1,
which is the difference between 2 and 1 (or between 2 and 3).

Note: There are at least two nodes in this BST.
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
    TreeNode* prev = nullptr;

public:
    int getMinimumDifference(TreeNode* root) {
        /* Recursion */
        // if (!root) {
        //     return INT_MAX;
        // }
        // int a = getMinimumDifference(root->left);
        // int b = INT_MAX;
        // if (prev) {
        //     b = root->val - prev->val;
        // }
        // prev = root;
        // int c = getMinimumDifference(root->right);
        // return (a < b ? (a < c ? a : c) : (b < c ? b : c));

        /* Iteration */
        stack<TreeNode*> node_stack;
        TreeNode* prev_node = nullptr;
        int diff = INT_MAX;
        TreeNode* node = root;
        while (node || !node_stack.empty()) {
            while (node) {
                node_stack.push(node);
                node = node->left;
            }
            node = node_stack.top();
            node_stack.pop();
            if (prev_node) {
                int curr_diff = node->val - prev_node->val;
                if (curr_diff < diff) {
                    diff = curr_diff;
                }
            }
            prev_node = node;
            node = node->right;
        }
        return diff;
    }
};