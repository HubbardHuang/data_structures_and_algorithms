/*
题目：二叉树中和为某一值的路径

题目描述：
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)
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
    void Calculate(TreeNode* root, int sum, int expect, vector<int>& buffer,
                   vector<vector<int>>& result) {
        if (!root) {
            return;
        }
        buffer.push_back(root->val);
        sum += root->val;
        if (!root->left && !root->right) {
            if (expect == sum) {
                result.push_back(buffer);
            }
            buffer.pop_back();
            return;
        } else if (sum >= expect) {
            buffer.pop_back();
            return;
        }
        Calculate(root->left, sum, expect, buffer, result);
        Calculate(root->right, sum, expect, buffer, result);
        buffer.pop_back();
    }

public:
    vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
        vector<vector<int>> result;
        result.clear();
        if (!root) {
            return result;
        }
        vector<int> buffer;
        Calculate(root, 0, expectNumber, buffer, result);
        return result;
    }
};
