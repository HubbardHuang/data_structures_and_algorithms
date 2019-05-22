/*
Title: Merge Two Binary Trees

Description:
Given two binary trees and imagine
that when you put one of them to cover the other,
some nodes of the two trees are overlapped
while the others are not.

You need to merge them into a new binary tree.
The merge rule is that if two nodes overlap,
then sum node values up as the new value of the merged node.
Otherwise, the NOT null node will be used as the node of new tree.

Example 1:
Input:
        Tree 1                     Tree 2
          1                         2
         / \                       / \
        3   2                     1   3
       /                           \   \
      5                             4   7
Output:
Merged tree:
             3
            / \
           4   5
          / \   \
         5   4   7

Note:
The merging process must start from the root nodes of both trees.
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
    /* Merge [t2] to [t1] and no change to [t2] */
    void MergeHelper0(TreeNode* t1, TreeNode* t2) {
        if (t1->left && t2->left) {
            t1->left->val += t2->left->val;
            MergeHelper0(t1->left, t2->left);
        } else if (!t1->left && t2->left) {
            TreeNode* node = new TreeNode(t2->left->val);
            t1->left = node;
            MergeHelper0(t1->left, t2->left);
        }
        if (t1->right && t2->right) {
            t1->right->val += t2->right->val;
            MergeHelper0(t1->right, t2->right);
        } else if (!t1->right && t2->right) {
            TreeNode* node = new TreeNode(t2->right->val);
            t1->right = node;
            MergeHelper0(t1->right, t2->right);
        }
    }
    /* Merge [t2] to [t1] and change [t2] */
    void MergeHelper1(TreeNode*& t1, TreeNode*& t2) {
        if (t1->left && t2->left) {
            t1->left->val += t2->left->val;
            MergeHelper1(t1->left, t2->left);
            delete t2->left;
            t2->left = nullptr;
        } else if (!t1->left && t2->left) {
            t1->left = t2->left;
        }
        if (t1->right && t2->right) {
            t1->right->val += t2->right->val;
            MergeHelper1(t1->right, t2->right);
            delete t2->right;
            t2->right = nullptr;
        } else if (!t1->right && t2->right) {
            t1->right = t2->right;
        }
    }
    /* Build a new tree and no change to [t1] and [t2] */
    TreeNode* MergeHelper2(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) {
            return nullptr;
        }
        int t1_val = 0;
        int t2_val = 0;
        TreeNode *t1_left = nullptr, *t1_right = nullptr;
        TreeNode *t2_left = nullptr, *t2_right = nullptr;
        if (t1) {
            t1_val = t1->val;
            t1_left = t1->left;
            t1_right = t1->right;
        }
        if (t2) {
            t2_val = t2->val;
            t2_left = t2->left;
            t2_right = t2->right;
        }

        TreeNode* node = new TreeNode(t1_val + t2_val);
        node->left = MergeHelper2(t1_left, t2_left);
        node->right = MergeHelper2(t1_right, t2_right);
        return node;
    }

public:
    TreeNode* mergeTrees(TreeNode*& t1, TreeNode*& t2) {
        if (!t1) {
            return t2;
        }
        if (!t2) {
            return t1;
        }

        /* Use [MergeHelper0] or [MergeHelper1] */
        // t1->val += t2->val;
        // MergeHelper1(t1, t2);
        // return t1;

        /* Use [MergeHelper2] */
        return MergeHelper2(t1, t2);
    }
};