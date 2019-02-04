/*
题目：二叉搜索树与双向链表

题目描述：
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
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
    void ToList(TreeNode* node, TreeNode*& prev) {
        if (!node) {
            return;
        }

        ToList(node->left, prev);

        if (prev) {
            prev->right = node;
        }
        node->left = prev;
        prev = node;

        ToList(node->right, prev);
    }

public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (!pRootOfTree) {
            return nullptr;
        }
        TreeNode* prev = nullptr;
        ToList(pRootOfTree, prev);
        while (pRootOfTree->left) {
            pRootOfTree = pRootOfTree->left;
        }
        return pRootOfTree;
    }
};
