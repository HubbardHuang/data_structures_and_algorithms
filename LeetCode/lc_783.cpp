/*
Title: Minimum Distance Between BST Nodes

Description:
Given a Binary Search Tree (BST) with the root node root,
return the minimum difference between the values
of any two different nodes in the tree.

Example :
Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.
The given tree [4,2,6,1,3,null,null] is represented by the following diagram:
          4
        /   \
      2      6
     / \
    1   3
while the minimum difference in this tree is 1,
it occurs between node 1 and node 2, also between node 3 and node 2.

Note:
    The size of the BST will be between 2 and 100.
    The BST is always valid, each node's value is an integer,
    and each node's value is different.
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
    int minDiffInBST(TreeNode* root) {
        stack<TreeNode*> node_stack;
        auto prev = root;
        while (prev->left) {
            prev = prev->left;
        }
        TreeNode* curr = root;
        int diff = INT_MAX;
        while (curr || !node_stack.empty()) {
            while (curr) {
                node_stack.push(curr);
                curr = curr->left;
            }
            curr = node_stack.top();
            node_stack.pop();

            if (curr != prev) {
                if (curr->val - prev->val < diff) {
                    diff = curr->val - prev->val;
                }
                prev = curr;
            }

            curr = curr->right;
        }
        return diff;
    }
};