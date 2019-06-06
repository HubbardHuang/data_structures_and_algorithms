/*
Title: Add Two Numbers

Description:
You are given two non-empty linked lists
representing two non-negative integers.
The digits are stored in reverse order
and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero,
except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *n1 = l1, *n2 = l2;
        for (; n1 && n2;) {
            n1 = n1->next;
            n2 = n2->next;
        }
        ListNode *longer = l1, *shorter = l2;
        if (!n1 && n2) {
            swap(longer, shorter);
        }

        ListNode* lo = longer;
        int carry = 0;
        for (ListNode* sh = shorter; lo;) {
            int sum = carry + lo->val + (sh ? sh->val : 0);
            carry = sum > 9 ? 1 : 0;
            lo->val = sum % 10;
            if (!lo->next && carry) {
                lo->next = new ListNode(carry);
                carry = 0;
            }
            lo = lo->next;
            sh = (sh ? sh->next : nullptr);
        }
        return longer;
    }
};