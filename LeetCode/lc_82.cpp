/*
Title: Remove Duplicates from Sorted List II

Description:
Given a sorted linked list,
delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list.

Example 1:
Input: 1->2->3->3->4->4->5
Output: 1->2->5

Example 2:
Input: 1->1->1->2->3
Output: 2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(INT_MIN);
        dummy.next = head;
        ListNode* prev = &dummy;
        while (prev && prev->next && prev->next->next) {
            ListNode* curr = prev->next;
            ListNode* next = prev->next->next;
            if (curr->val == next->val) {
                int key = curr->val;
                while (curr && curr->val == key) {
                    ListNode* temp = curr;
                    curr = curr->next;
                    delete temp;
                }
                prev->next = curr;
                if (curr) {
                    key = curr->val;
                }
            } else {
                prev = prev->next;
            }
        }
        return dummy.next;
    }
};