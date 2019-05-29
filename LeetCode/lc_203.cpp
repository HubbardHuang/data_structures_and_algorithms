/*
Title: Remove Linked List Elements

Description:
Remove all elements from a linked list of integers that have value val.

Example:
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
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
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(INT_MIN);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = prev->next;
        while (curr) {
            if (curr->val != val) {
                curr = curr->next;
                prev = prev->next;
            } else {
                ListNode* temp = curr->next;
                prev->next = temp;
                delete curr;
                curr = temp;
            }
        }
        return dummy.next;
    }
};