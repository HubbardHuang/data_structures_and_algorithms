/*
Title: Binary Tree Level Order Traversal II

Description:
Given a binary tree,
return the bottom-up level order traversal of its nodes' values.
(ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        queue<pair<TreeNode*, int>> node_queue;
        if (!root) {
            return result;
        }
        node_queue.push({ root, 0 });
        vector<int> buffer;
        while (!node_queue.empty()) {
            auto curr = node_queue.front();
            node_queue.pop();
            buffer.push_back(curr.first->val);
            if (curr.first->left) {
                node_queue.push({ curr.first->left, curr.second + 1 });
            }
            if (curr.first->right) {
                node_queue.push({ curr.first->right, curr.second + 1 });
            }
            if (!node_queue.empty() &&
                  curr.second != node_queue.front().second ||
                node_queue.empty()) {
                result.push_back(buffer);
                buffer.clear();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};