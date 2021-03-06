/*
Title: Linked List Cycle

Description:
Given a linked list,
determine if it has a cycle in it.
To represent a cycle in the given linked list,
we use an integer pos
which represents the position (0-indexed) in the linked list
where tail connects to.
If pos is -1,
then there is no cycle in the linked list.
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
    bool hasCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};