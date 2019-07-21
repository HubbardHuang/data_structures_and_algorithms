/*
Title: Maximum Binary Tree

Description:
Given an integer array with no duplicates. 
A maximum tree building on this array is defined as follow:
The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:
      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1

Note:
The size of the given array will be in the range [1,1000].
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
class Solution
{
private:
    struct NodeInfo
    {
        TreeNode *ptr;
        int idx;
        int left;
        int right;
        NodeInfo(TreeNode *p, int i, int l, int r)
            : ptr(p), idx(i), left(l), right(r) {}
    };
    NodeInfo FindMax(vector<int> &nums, int left, int right)
    {
        int max = INT_MIN;
        int idx = -1;
        for (int i = left; i < right; i++)
        {
            if (max < nums[i])
            {
                max = nums[i];
                idx = i;
            }
        }
        auto ptr = new TreeNode(max);
        return NodeInfo(ptr, idx, left, right);
    }

public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.empty())
        {
            return nullptr;
        }
        auto root = FindMax(nums, 0, nums.size());
        stack<decltype(root)> node_stack;
        node_stack.push(root);
        while (!node_stack.empty())
        {
            auto curr_root = node_stack.top();
            node_stack.pop();
            if (curr_root.idx > 0 && curr_root.idx != curr_root.left)
            {
                auto left_son = FindMax(nums, curr_root.left, curr_root.idx);
                curr_root.ptr->left = left_son.ptr;
                node_stack.push(left_son);
            }
            if (curr_root.idx < nums.size() - 1 && curr_root.idx + 1 != curr_root.right)
            {
                auto right_son = FindMax(nums, curr_root.idx + 1, curr_root.right);
                curr_root.ptr->right = right_son.ptr;
                node_stack.push(right_son);
            }
        }
        return root.ptr;
    }
};
