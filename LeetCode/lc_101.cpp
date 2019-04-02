/*
Title: Symmetric Tree

Description:
Given a binary tree,
check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool isSymmetricHelper(TreeNode* left_node, TreeNode* right_node) {
        if (!left_node || !right_node) {
            return left_node == right_node;
        }
        if (left_node->val != right_node->val) {
            return false;
        }
        return isSymmetricHelper(left_node->left, right_node->right) &&
               isSymmetricHelper(left_node->right, right_node->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        /* Recursion */
        // return root == nullptr || isSymmetricHelper(root->left, root->right);

        /* Iteration */
        if (!root) {
            return true;
        }
        using NodePair = pair<TreeNode*, TreeNode*>;
        stack<NodePair> s;
        s.push({ root->left, root->right });
        while (!s.empty()) {
            NodePair np = s.top();
            s.pop();
            if (!np.first || !np.second) {
                if (np.first != np.second) {
                    return false;
                } else {
                    continue;
                }
            }
            if (np.first->val != np.second->val) {
                return false;
            }
            if (np.first && np.second) {
                s.push({ np.first->left, np.second->right });
                s.push({ np.first->right, np.second->left });
            }
        }
        return true;
    }
};