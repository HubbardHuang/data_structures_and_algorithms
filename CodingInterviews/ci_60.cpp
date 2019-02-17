/*
题目：把二叉树打印成多行

题目描述：
从上到下按层打印二叉树，同一层结点从左至右输出。
每一层输出一行。
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
    vector<vector<int>> Print(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            result.clear();
            return result;
        }
        using TreePair = pair<TreeNode*, int>;
        queue<TreePair> q;
        TreePair node;
        vector<int> buffer;
        int level = 1;
        q.push({ root, level });
        while (!q.empty()) {
            node = q.front();
            q.pop();

            if (node.second == level) {
                buffer.push_back(node.first->val);
            } else {
                level = node.second;
                result.push_back(buffer);
                buffer.clear();
                buffer.push_back(node.first->val);
            }

            if (node.first->left) {
                q.push({ node.first->left, node.second + 1 });
            }
            if (node.first->right) {
                q.push({ node.first->right, node.second + 1 });
            }
        }
        result.push_back(buffer);
        return result;
    }
};