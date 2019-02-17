/*
题目：二叉搜索树的第k个结点

题目描述：
给定一棵二叉搜索树，请找出其中的第k小的结点。
例如，（5，3，7，2，4，6，8）中，按结点数值大小顺序第三小结点的值为4。
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
    TreeNode* KthNode(TreeNode* root, int k) {
        /*
        // 不带返回值的递归函数
        TreeNode* target = nullptr;
        int count = 0;
        InOrder(root, count, k, target);
        return target;
        */
        // 带返回值的递归函数
        int count = 0;
        return InOrder(root, count, k);
    }

private:
    // 不带返回值的递归函数
    void InOrder(TreeNode* node, int& count, int k, TreeNode*& target) {
        if (!node) {
            return;
        }
        InOrder(node->left, count, k, target);
        ++count;
        if (count == k) {
            target = node;
        } else {
            InOrder(node->right, count, k, target);
        }
    }
    // 带返回值的递归函数
    TreeNode* InOrder(TreeNode* node, int& count, int k) {
        if (!node) {
            return nullptr;
        }
        TreeNode* target;
        target = InOrder(node->left, count, k);
        if (target) {
            return target;
        }
        ++count;
        if (count == k) {
            return node;
        }
        target = InOrder(node->right, count, k);
        if (target) {
            return target;
        }
        return nullptr;
    }
};