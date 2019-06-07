/*
Title: Remove Nth Node From End of List

Description:
Given a linked list,
remove the n-th node from the end of list and return its head.

Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end,
the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.

Follow up:
Could you do this in one pass?
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
    void Delete(ListNode* head, ListNode* node) {
        if (!node->next) {
            for (ListNode* i = head; i; i = i->next) {
                if (i->next == node) {
                    i->next = nullptr;
                    delete node;
                    break;
                }
            }
        } else {
            ListNode* temp = node->next;
            node->val = temp->val;
            node->next = temp->next;
            delete temp;
        }
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head;
        for (int i = 0; i < n && fast; i++) {
            fast = fast->next;
        }
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode dummy(-1);
        dummy.next = head;
        Delete(&dummy, slow);
        return dummy.next;
    }
};