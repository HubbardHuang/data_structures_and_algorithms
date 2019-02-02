/*
题目：从上往下打印二叉树

题目描述：
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
    queue<TreeNode*> q;

public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        result.clear();
        if (!root) {
            return result;
        }
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            result.push_back(node->val);
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        return result;
    }
};
