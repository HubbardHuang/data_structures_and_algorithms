/*
题目：树的子结构

题目描述：
输入两棵二叉树A，B，判断B是不是A的子结构。
（ps：我们约定空树不是任意一个树的子结构）
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
    bool HasSubtree(TreeNode* root1, TreeNode* root2) {
        bool result = false;
        if (root1 && root2) {
            if (root1->val == root2->val) {
                result = IsSubtree(root1, root2);
            }
            if (!result) {
                result = HasSubtree(root1->left, root2);
            }
            if (!result) {
                result = HasSubtree(root1->right, root2);
            }
        }
        return result;
    }
    bool IsSubtree(TreeNode* root1, TreeNode* root2) {
        if (!root2) {
            return true;
        }
        if (!root1) {
            return false;
        }
        if (root1->val != root2->val) {
            return false;
        }
        return IsSubtree(root1->left, root2->left) &&
               IsSubtree(root1->right, root2->right);
    }
};
