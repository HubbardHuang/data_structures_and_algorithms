/*
Title: Sum of Root To Leaf Binary Numbers

Description:
Given a binary tree, each node has value 0 or 1.
Each root-to-leaf path represents a binary number
starting with the most significant bit.
For example, if the path is 0 -> 1 -> 1 -> 0 -> 1,
then this could represent 01101 in binary, which is 13.
For all leaves in the tree,
consider the numbers represented by the path from the root to that leaf.
Return the sum of these numbers.

Example 1:
Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

Note:
    The number of nodes in the tree is between 1 and 1000.
    node.val is 0 or 1.
    The answer will not exceed 2^31 - 1.
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
    int sumRootToLeaf(TreeNode* root, int prev = 0) {
        /* Recursion */
        // if (!root) {
        //     return 0;
        // }
        // int curr = prev * 2 + root->val;
        // if (!root->left && !root->right) {
        //     return curr;
        // } else {
        //     return sumRootToLeaf(root->left, curr) +
        //            sumRootToLeaf(root->right, curr);
        // }

        /* Iteration */
        using Node = pair<TreeNode*, int>;
        stack<Node> node_stack;
        if (!root) {
            return 0;
        }
        int sum = 0;
        node_stack.push(Node(root, 0));
        while (!node_stack.empty()) {
            auto curr_node = node_stack.top();
            node_stack.pop();
            int curr_val = curr_node.second * 2 + curr_node.first->val;
            if (!curr_node.first->left && !curr_node.first->right) {
                sum += curr_val;
            } else {
                if (curr_node.first->right) {
                    node_stack.push(Node(curr_node.first->right, curr_val));
                }
                if (curr_node.first->left) {
                    node_stack.push(Node(curr_node.first->left, curr_val));
                }
            }
        }
        return sum;
    }
};