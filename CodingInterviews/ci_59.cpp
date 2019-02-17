/*
题目：按之字形顺序打印二叉树

题目描述：
请实现一个函数按照之字形打印二叉树，
即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，
第三行按照从左到右的顺序打印，
其他行以此类推。
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
    typedef pair<TreeNode*, int> TreePair;
    vector<vector<int>> Print(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            result.clear();
            return result;
        }
        queue<TreePair> q;
        q.push({ root, 1 });
        int prev_level = 1;
        vector<int> one_level_buffer;
        TreePair node;
        while (!q.empty()) {
            node = q.front();
            q.pop();

            if (node.second == prev_level) {
                one_level_buffer.push_back(node.first->val);
            } else {
                if (!(node.second - 1 & 1)) {
                    reverse(one_level_buffer.begin(), one_level_buffer.end());
                }
                result.push_back(one_level_buffer);
                one_level_buffer.clear();
                prev_level = node.second;
                one_level_buffer.push_back(node.first->val);
            }

            if (node.first->left) {
                q.push({ node.first->left, node.second + 1 });
            }
            if (node.first->right) {
                q.push({ node.first->right, node.second + 1 });
            }
        }
        if (!(node.second & 1)) {
            reverse(one_level_buffer.begin(), one_level_buffer.end());
        }
        result.push_back(one_level_buffer);

        return result;
    }
};