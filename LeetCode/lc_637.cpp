/*
Title: Average of Levels in Binary Tree

Description:
Given a non-empty binary tree,
return the average value of the nodes
on each level in the form of an array.

Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,
on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].

Note:
The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<pair<TreeNode*, int>> node_queue;
        vector<double> result;
        if (!root) {
            return {};
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
                  node_queue.front().second != curr.second ||
                node_queue.empty()) {
                long long sum = 0;
                for (auto i : buffer) {
                    sum += i;
                }
                result.push_back(static_cast<double>(static_cast<double>(sum) /
                                                     buffer.size()));
                buffer.clear();
            }
        }
        return result;
    }
};