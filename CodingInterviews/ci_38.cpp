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
    int GetHeight(TreeNode* node, int height) {
        if (!node) {
            return height;
        }
        return max(GetHeight(node->left, height + 1), GetHeight(node->right, height + 1));
    }

public:
    int TreeDepth(TreeNode* root) { return GetHeight(root, 0); }
};