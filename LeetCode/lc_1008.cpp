/*
Title: Construct Binary Search Tree from Preorder Traversal

Description:
Return the root node of a binary search tree that matches the given preorder traversal.
(Recall that a binary search tree is a binary tree where for every node, 
any descendant of node.left has a value < node.val, 
and any descendant of node.right has a value > node.val. 
Also recall that a preorder traversal displays the value of the node first, 
then traverses node.left, then traverses node.right.)

Example 1:
Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Note: 
1 <= preorder.length <= 100
The values of preorder are distinct.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
    struct Node
    {
        TreeNode *father;
        int left;
        // int mid;
        int right;
        Node(TreeNode *p, int l, int r) : father(p), left(l), right(r) {}
    };

public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int left = 0;
        int right = preorder.size() - 1;
        TreeNode *root = new TreeNode(preorder[left]);
        stack<Node> node_stack;
        if (left < right)
        {
            node_stack.push(Node(root, left + 1, right));
        }
        while (!node_stack.empty())
        {
            auto curr = node_stack.top();
            node_stack.pop();
            int mid = -1;
            bool no_right = true;
            for (int i = curr.left; i <= curr.right; i++)
            {
                if (preorder[i] > curr.father->val)
                {
                    mid = i;
                    no_right = false;
                    break;
                }
            }
            if (mid == -1)
            {
                mid = curr.right + 1;
            }
            if (preorder[curr.left] < curr.father->val)
            {
                auto left_son = new TreeNode(preorder[curr.left]);
                curr.father->left = left_son;
                if (mid - curr.left - 1 > 0)
                {
                    node_stack.push(Node(left_son, curr.left + 1, mid - 1));
                }
            }
            if (mid != curr.right + 1)
            {
                auto right_son = new TreeNode(preorder[mid]);
                curr.father->right = right_son;
                if (curr.right - mid > 0)
                {
                    node_stack.push(Node(right_son, mid + 1, curr.right));
                }
            }
        }
        return root;
    }
};