/*
Title: Convert Sorted Array to Binary Search Tree

Description:
Given an array where elements are sorted in ascending order,
convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree
in which the depth of the two subtrees of every node never differ by more than 1.

Example:
Given the sorted array: [-10,-3,0,5,9],
One possible answer is: [0,-3,9,-10,null,5],
which represents the following height balanced BST:
      0
     / \
   -3   9
   /   /
 -10  5
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
    TreeNode* CreateNode(const vector<int>& nums, int start_index, int end_index) {
        if (start_index > end_index) {
            return nullptr;
        }
        int root_index = (start_index + end_index) / 2;
        TreeNode* node = new TreeNode(nums[root_index]);
        node->left = CreateNode(nums, start_index, root_index - 1);
        node->right = CreateNode(nums, root_index + 1, end_index);
        return node;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int length = nums.size();
        int start_index = 0;
        int end_index = length - 1;
        return CreateNode(nums, start_index, end_index);
    }
};