/*
Title: Binary Tree Paths

Description:
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:
Input:
   1
 /   \
2     3
 \
  5
Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    void Helper(TreeNode* node, string buffer, vector<string>& result) {
        if (!node->left && !node->right) {
            result.push_back(buffer);
        } else {
            if (node->left) {
                Helper(node->left, buffer + "->" + to_string(node->left->val),
                       result);
            }
            if (node->right) {
                Helper(node->right, buffer + "->" + to_string(node->right->val),
                       result);
            }
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) {
            return result;
        }
        string start = to_string(root->val);
        Helper(root, start, result);
        return result;
    }
};