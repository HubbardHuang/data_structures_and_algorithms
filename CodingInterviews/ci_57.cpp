/*
题目：二叉树的下一个结点

题目描述：
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/

/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode* left;
    struct TreeLinkNode* right;
    struct TreeLinkNode* next;
    TreeLinkNode(int x)
      : val(x)
      , left(NULL)
      , right(NULL)
      , next(NULL) {}
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* node) {
        if (!node->next && !node->right) {
            return nullptr;
        }
        // 若有右孩子或为根结点，则寻找其右孩子的最左后嗣
        if (node->right || !node->next) {
            TreeLinkNode* target = node->right;
            while (target->left) {
                target = target->left;
            }
            return target;
        }
        // 若无右孩子，且为其父的左孩子，则返回其父结点
        if (!node->right && node == node->next->left) {
            return node->next;
        }
        // 若无右孩子，且为其父的右孩子
        if (!node->right && node == node->next->right) {
            TreeLinkNode* father = node->next;
            while (father->next) {
                TreeLinkNode* grandpa = father->next;
                if (father == grandpa->left) {
                    return grandpa;
                }
                if (!grandpa->next && father == grandpa->right) {
                    return nullptr;
                }
                father = grandpa;
            }
        }
        return nullptr;
    }
};