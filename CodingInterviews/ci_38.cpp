/*
题目：二叉树的深度

题目描述：
输入一棵二叉树，求该树的深度。
从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
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
private:
    // 法一
    int GetHeight(TreeNode* node, int height) {
        if (!node) {
            return height;
        }
        return max(GetHeight(node->left, height + 1), GetHeight(node->right, height + 1));
    }
    // 法二
    int GetHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left_height = GetHeight(root->left) + 1;
        int right_height = GetHeight(root->right) + 1;
        return max(left_height, right_height);
    }

public:
    int TreeDepth(TreeNode* root) {
        // // 法一
        // return GetHeight(root, 0);

        // 法二
        return GetHeight(root);
    }
};