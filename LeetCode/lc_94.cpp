/*
Title: Binary Tree Inorder Traversal

Description:
Given a binary tree, return the inorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3
Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
    enum class Method { kRecursive, kIterative };
    void PrintInOrder(TreeNode* node, vector<int>& buffer, Method method) {
        if (method == Method::kRecursive) {
            PrintInOrderRecursively(node, buffer);
        } else if (method == Method::kIterative) {
            PrintInOrderIteratively(node, buffer);
        }
    }
    void PrintInOrderIteratively(TreeNode* node, vector<int>& buffer) {
        stack<TreeNode*> waiting;
        while (node || !waiting.empty()) {
            while (node) {
                waiting.push(node);
                node = node->left;
            }
            node = waiting.top();
            waiting.pop();
            buffer.push_back(node->val);
            node = node->right;
        }
    }
    void PrintInOrderRecursively(TreeNode* node, vector<int>& buffer) {
        if (!node) {
            return;
        }
        PrintInOrderRecursively(node->left, buffer);
        buffer.push_back(node->val);
        PrintInOrderRecursively(node->right, buffer);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> buffer;
        PrintInOrder(root, buffer, Method::kIterative);
        return buffer;
    }
};