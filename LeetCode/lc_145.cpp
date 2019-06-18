/*
Title: Binary Tree Postorder Traversal

Description:
Given a binary tree,
return the postorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3
Output: [3,2,1]

Follow up:
Recursive solution is trivial,
could you do it iteratively?
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> buffer;
        if (!root) {
            return buffer;
        }
        stack<TreeNode*> node_stack;
        node_stack.push(root);
        while (!node_stack.empty()) {
            auto p = node_stack.top();
            buffer.push_back(p->val);
            node_stack.pop();
            if (p->left) {
                node_stack.push(p->left);
            }
            if (p->right) {
                node_stack.push(p->right);
            }
        }
        reverse(buffer.begin(), buffer.end());
        return buffer;
    }
};