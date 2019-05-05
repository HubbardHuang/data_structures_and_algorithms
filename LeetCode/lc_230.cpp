/*
Title: Kth Smallest Element in a BST

Description:
Given a binary search tree,
write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid,
1 ≤ k ≤ BST's total elements.

Example 1:
Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3

Follow up:
What if the BST is modified (insert/delete operations) often
and you need to find the kth smallest frequently?
How would you optimize the kthSmallest routine?
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
    void InOrder(TreeNode* node, int& count, int k, int& result) {
        if (!node) {
            return;
        }
        InOrder(node->left, count, k, result);

        ++count;
        if (count == k) {
            result = node->val;
            return;
        }

        InOrder(node->right, count, k, result);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = 0;
        InOrder(root, count, k, result);
        return result;
    }
};