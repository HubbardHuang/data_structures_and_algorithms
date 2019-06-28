/*
Title: Two Sum IV - Input is a BST

Description:
Given a Binary Search Tree and a target number,
return true if there exist two elements in the BST
such that their sum is equal to the given target.

Example 1:
Input:
    5
   / \
  3   6
 / \   \
2   4   7
Target = 9
Output: True

Example 2:
Input:
    5
   / \
  3   6
 / \   \
2   4   7
Target = 28
Output: False
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
    void Inorder(TreeNode* node, vector<int>& buffer) {
        if (!node) {
            return;
        }
        Inorder(node->left, buffer);
        buffer.push_back(node->val);
        Inorder(node->right, buffer);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> buffer;
        Inorder(root, buffer);
        int left = 0, right = buffer.size() - 1;
        while (left < right) {
            int sum = buffer[left] + buffer[right];
            if (sum == k) {
                return true;
            } else if (sum < k) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
};