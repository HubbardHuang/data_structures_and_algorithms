/*
Title: Merge Two Sorted Lists

Description:
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* MergeIteratively(ListNode* left, ListNode* right) {
        if (!left) {
            return right;
        }
        if (!right) {
            return left;
        }
        ListNode dummy(-1);
        ListNode* node = &dummy;
        while (left && right) {
            if (left->val <= right->val) {
                node->next = left;
                left = left->next;
            } else if (right->val < left->val) {
                node->next = right;
                right = right->next;
            }
            node = node->next;
        }
        if (!left) {
            node->next = right;
        } else {
            node->next = left;
        }
        return dummy.next;
    }
    ListNode* MergeRecursively(ListNode* left, ListNode* right) {
        if (!left) {
            return right;
        }
        if (!right) {
            return left;
        }
        ListNode* node;
        if (left->val < right->val) {
            node = left;
            node->next = MergeRecursively(left->next, right);
        } else {
            node = right;
            node->next = MergeRecursively(left, right->next);
        }
        return node;
    }

public:
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        return MergeIteratively(left, right);
        return MergeRecursively(left, right);
    }
};