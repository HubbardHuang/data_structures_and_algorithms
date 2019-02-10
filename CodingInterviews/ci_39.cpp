/*
题目：平衡二叉树

题目描述：
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/

/*
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x)
      : val(x)
      , left(NULL)
      , right(NULL) {}
};
*/
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* root) {
        // 法一
        // return JudgeRecursively(root);

        // 法二
        return GetDepth(root) != -1;
    }

private:
    // 法一
    int GetHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left_height = GetHeight(root->left) + 1;
        int right_height = GetHeight(root->right) + 1;
        return max(left_height, right_height);
    }
    bool JudgeRecursively(TreeNode* root) {
        if (!root) {
            return true;
        }
        int left_height = GetHeight(root->left);
        int right_height = GetHeight(root->right);
        return abs(left_height - right_height) <= 1 && JudgeRecursively(root->left) &&
               JudgeRecursively(root->right);
    }
    // 法二
    int GetDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left_depth = GetDepth(root->left);
        if (left_depth == -1) {
            return -1;
        }
        int right_depth = GetDepth(root->right);
        if (right_depth == -1) {
            return -1;
        }
        if (abs(right_depth - left_depth) <= 1) {
            return 1 + max(left_depth, right_depth);
        } else {
            return -1;
        }
    }
};