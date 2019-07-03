/*
Title: Sum of Left Leaves

Description:
Find the sum of all left leaves in a given binary tree.

Example:
    3
   / \
  9  20
    /  \
   15   7
There are two left leaves in the binary tree,
with values 9 and 15 respectively. Return 24.
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
    int Helper(TreeNode* dad, TreeNode* son) {
        if (!dad) {
            return 0;
        }
        if (!son) {
            return 0;
        }
        if (dad->left == son) {
            if (!son->left && !son->right) {
                return son->val;
            }
        }
        return Helper(son, son->left) + Helper(son, son->right);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        /* Recursion */
        // if (!root) {
        //     return 0;
        // }
        // return Helper(root, root->left) + Helper(root, root->right);

        /* Iteration */
        const int kLeft = 1;
        const int kRight = 2;
        int result = 0;
        stack<pair<decltype(root), int>> node_stack;
        node_stack.push({ root, 2 });
        while (!node_stack.empty()) {
            auto curr = node_stack.top();
            node_stack.pop();
            if (!curr.first) {
                continue;
            }
            if (curr.second == kLeft && !curr.first->left &&
                !curr.first->right) {
                result += curr.first->val;
            }
            node_stack.push({ curr.first->left, kLeft });
            node_stack.push({ curr.first->right, kRight });
        }
        return result;
    }
};