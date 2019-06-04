/*
Title: Palindrome Linked List

Description:
Given a singly linked list,
determine if it is a palindrome.

Example 1:
Input: 1->2
Output: false

Example 2:
Input: 1->2->2->1
Output: true

Follow up:
Could you do it in O(n) time and O(1) space?
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
    ListNode* ReverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *left_half = head, *right_half = slow->next;
        slow->next = nullptr;
        right_half = ReverseList(right_half);
        for (ListNode *l = left_half, *r = right_half; l && r;
             l = l->next, r = r->next) {
            if (l->val != r->val) {
                return false;
            }
        }
        return true;
    }
};