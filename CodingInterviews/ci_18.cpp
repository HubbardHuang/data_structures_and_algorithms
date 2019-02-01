/*
题目：二叉树的镜像

题目描述：
操作给定的二叉树，将其变换为源二叉树的镜像。
二叉树的镜像定义：
        源二叉树
            8
           /  \
          6   10
         / \  / \
        5  7 9 11
        镜像二叉树
            8
           /  \
          10   6
         / \  / \
        11 9 7  5
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
    /*
    // 递归解法
    void Mirror(TreeNode* pRoot) {
        if (pRoot) {
            swap(pRoot->left, pRoot->right);
            Mirror(pRoot->left);
            Mirror(pRoot->right);
        }
    }
    */
    // 栈循环解法，从第一层的根节点开始操作
    void Mirror(TreeNode* pRoot) {
        if (!pRoot) {
            return;
        }
        stack<TreeNode*> tree_stack;
        tree_stack.push(pRoot);
        while (!tree_stack.empty()) {
            TreeNode* node = tree_stack.top();
            tree_stack.pop();
            swap(node->left, node->right);
            if (node->left) {
                tree_stack.push(node->left);
            }
            if (node->right) {
                tree_stack.push(node->right);
            }
        }
    }
};
