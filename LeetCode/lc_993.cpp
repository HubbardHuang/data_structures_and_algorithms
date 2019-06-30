/*
Title: Cousins in Binary Tree

Description:
In a binary tree,
the root node is at depth 0,
and children of each depth k node are at depth k+1.
Two nodes of a binary tree are cousins
if they have the same depth, but have different parents.
We are given the root of a binary tree with unique values,
and the values x and y of two different nodes in the tree.
Return true if and
only if the nodes corresponding to the values x and y are cousins.
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
    struct Node {
        TreeNode* ptr;
        TreeNode* dad;
        int depth;
        Node(TreeNode* p, TreeNode* d, int dep)
          : ptr(p)
          , dad(d)
          , depth(dep) {}
    };
    Node DFS(TreeNode* dad, int num, int depth) {
        if (!dad) {
            return Node(nullptr, nullptr, depth);
        }
        if (dad->left && dad->left->val == num) {
            return Node(dad->left, dad, depth);
        }
        if (dad->right && dad->right->val == num) {
            return Node(dad->right, dad, depth);
        }
        auto left_result = DFS(dad->left, num, depth + 1);
        auto right_result = DFS(dad->right, num, depth + 1);
        if (left_result.ptr) {
            return left_result;
        }
        if (right_result.ptr) {
            return right_result;
        }
        return Node(nullptr, dad, depth);
    }
    Node BFS(TreeNode* root, int num) {
        queue<Node> node_queue;
        node_queue.push(Node(root, nullptr, 0));
        while (!node_queue.empty()) {
            auto node = node_queue.front();
            node_queue.pop();
            if (!node.ptr) {
                continue;
            }
            if (node.ptr->val == num) {
                return node;
            }
            node_queue.push(Node(node.ptr->left, node.ptr, node.depth + 1));
            node_queue.push(Node(node.ptr->right, node.ptr, node.depth + 1));
        }
        return Node(nullptr, nullptr, -1);
    }
    Node Find(TreeNode* root, int num) {
        // if (!root) {
        //     return Node(nullptr, nullptr, -1);
        // }
        // if (root->val == num) {
        //     return Node(root, nullptr, 0);
        // }
        // return DFS(root, num, 1);
        return BFS(root, num);
    }

public:
    bool isCousins(TreeNode* root, int x, int y) {
        auto left = Find(root, x);
        auto right = Find(root, y);
        if (left.ptr && right.ptr) {
            return left.dad && right.dad && left.dad != right.dad &&
                   left.depth == right.depth;
        } else {
            return false;
        }
    }
};