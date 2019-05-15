/*
Title: Sort List

Description:
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:
Input: 4->2->1->3
Output: 1->2->3->4

Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
    /* Method 1 */
    ListNode* Merge(ListNode* head) {
        /* Get the length of the list */
        int length = 0;
        for (ListNode* node = head; node; node = node->next) {
            length++;
        }

        /* Merge fron bottom to top */
        ListNode dummy(INT_MIN);
        dummy.next = head;
        ListNode* curr_head = head;
        for (int step = 1; step < length; step <<= 1) {
            ListNode* curr = dummy.next;
            ListNode* tail = &dummy;
            while (curr) {
                ListNode* left = curr;
                ListNode* right = Cut(left, step);
                curr = Cut(right, step);
                tail = MergeTwoSortedLists(left, right, tail);
            }
        }
        return dummy.next;
    }
    ListNode* Cut(ListNode* head, int step) {
        for (int i = 1; head && i < step; i++) {
            head = head->next;
        }
        if (!head) {
            return nullptr;
        }
        ListNode* second = head->next;
        head->next = nullptr;
        return second;
    }
    ListNode* MergeTwoSortedLists(ListNode* left, ListNode* right,
                                  ListNode* head) {
        ListNode* curr = head;
        while (left && right) {
            if (left->val < right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        if (left) {
            curr->next = left;
        } else {
            curr->next = right;
        }
        while (curr->next) {
            curr = curr->next;
        }
        return curr;
    }
    /* Method 2 */
    ListNode* Partition(ListNode* head, ListNode* tail) {
        if (!head || !head->next || head->next == tail) {
            return head;
        }
        ListNode* pivot = head;
        ListNode* left = head;
        for (ListNode* right = head->next; right && right != tail;
             right = right->next) {
            if (right->val < pivot->val) {
                left = left->next;
                swap(left->val, right->val);
            }
        }
        swap(left->val, pivot->val);
        return left;
    }
    void PartitionRecursion(ListNode* head, ListNode* tail) {
        if (!head || !head->next || head == tail) {
            return;
        }
        ListNode* pivot = Partition(head, tail);
        PartitionRecursion(head, pivot);
        PartitionRecursion(pivot->next, tail);
    }

public:
    ListNode* sortList(ListNode* head) {
        /* Method 1: Do like quick-sort */
        // PartitionRecursion(head, nullptr);

        /* Method 2: Do like merge-sort */
        return Merge(head);
    }
};