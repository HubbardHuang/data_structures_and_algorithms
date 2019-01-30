/*
题目：重建二叉树

题目描述：
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // pre：先序遍历序列  in：中序遍历序列
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
        // 法一
        // TreeNode* root = nullptr;
        // GetRoot(root, pre, in, 0, 0, in.size() - 1);
        // return root;

        // 法二
        TreeNode* root = GetRoot(pre, in, 0, 0, in.size() - 1);
        return root;
    }

private:
    // 法一
    void GetRoot(TreeNode*& root, const vector<int>& pre, const vector<int>& in,
                 int pre_root_position, int in_start_position, int in_end_position) {
        if (in_start_position > in_end_position) {
            return;
        }
        root = new TreeNode(pre[pre_root_position]);

        // 寻找中序遍历序列中根节点的索引
        int in_root_position;
        for (in_root_position = in_start_position; in_root_position <= in_end_position;
             in_root_position++) {
            if (in[in_root_position] == pre[pre_root_position]) {
                break;
            }
        }

        GetRoot(root->left, pre, in, pre_root_position + 1, in_start_position,
                in_root_position - 1);
        GetRoot(root->right, pre, in,
                pre_root_position + (in_root_position - in_start_position + 1),
                in_root_position + 1, in_end_position);
    }
    // 法二
    TreeNode* GetRoot(const vector<int>& pre, const vector<int>& in,
                      int pre_root_position, int in_start_position, int in_end_position) {
        if (in_start_position > in_end_position) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(pre[pre_root_position]);

        // 寻找中序遍历序列中根节点的索引
        int in_root_position;
        for (in_root_position = in_start_position; in_root_position <= in_end_position;
             in_root_position++) {
            if (in[in_root_position] == pre[pre_root_position]) {
                break;
            }
        }

        root->left = GetRoot(pre, in, pre_root_position + 1, in_start_position,
                             in_root_position - 1);
        root->right =
          GetRoot(pre, in, pre_root_position + (in_root_position - in_start_position + 1),
                  in_root_position + 1, in_end_position);

        return root;
    }
};