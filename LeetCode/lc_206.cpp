/*
Title: Reverse Linked List

Description:
Reverse a singly linked list.

Example:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Follow up:
A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseList(ListNode* head) {
        // return ReverseListIteratively(head);
        return ReverseListRecursively(nullptr, head);
    }

private:
    ListNode* ReverseListRecursively(ListNode* prev, ListNode* curr) {
        if (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            return ReverseListRecursively(curr, next);
        } else {
            return prev;
        }
    }
    ListNode* ReverseListIteratively(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* curr = head;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};