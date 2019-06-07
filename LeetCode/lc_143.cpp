/*
Title: Reorder List

Description:
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
You may not modify the values in the list's nodes,
only nodes itself may be changed.

Example 1:
Given 1->2->3->4, reorder it to 1->4->2->3.

Example 2:
Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
    ListNode* Reverse(ListNode* head) {
        ListNode *prev = nullptr, *next = nullptr;
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

public:
    void reorderList(ListNode* head) {
        if (!head) {
            return;
        }
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *left = head, *right = Reverse(slow->next);
        slow->next = nullptr;

        ListNode dummy(-1);
        ListNode* node = &dummy;
        ListNode *l = left, *r = right;
        while (l || r) {
            if (l) {
                node->next = l;
                l = l->next;
                node = node->next;
            }
            if (r) {
                node->next = r;
                r = r->next;
                node = node->next;
            }
        }
    }
};