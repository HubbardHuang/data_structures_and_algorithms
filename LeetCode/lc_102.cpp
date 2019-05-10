/*
Title: Binary Tree Level Order Traversal

Description:
Given a binary tree,
return the level order traversal of its nodes' values.
(ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
private:
    typedef struct Node {
        TreeNode* ptr;
        int level;
    } Node;

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        queue<Node> node_queue;
        node_queue.push({ root, 0 });
        vector<int> buffer;
        int prev_level = 0;
        while (!node_queue.empty()) {
            Node curr_node = node_queue.front();
            node_queue.pop();

            if (prev_level == curr_node.level) {
                buffer.push_back(curr_node.ptr->val);
            } else {
                result.push_back(buffer);
                buffer.clear();
                buffer.push_back(curr_node.ptr->val);
            }

            if (curr_node.ptr->left) {
                node_queue.push({ curr_node.ptr->left, curr_node.level + 1 });
            }
            if (curr_node.ptr->right) {
                node_queue.push({ curr_node.ptr->right, curr_node.level + 1 });
            }
            prev_level = curr_node.level;
        }
        if (!buffer.empty()) {
            result.push_back(buffer);
        }
        return result;
    }
};