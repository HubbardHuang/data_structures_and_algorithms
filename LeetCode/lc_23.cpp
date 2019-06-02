/*
Title: Merge k Sorted Lists

Description:
Merge k sorted linked lists and return it as one sorted list.
Analyze and describe its complexity.

Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
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
    void DeleteHead(ListNode*& head) {
        if (!head) {
            return;
        } else if (!head->next) {
            head = nullptr;
        } else {
            ListNode* temp = head->next;
            head->next = temp->next;
            head->val = temp->val;
            delete temp;
        }
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* left, const ListNode* right) {
            if (left->val > right->val) {
                return true;
            } else {
                return false;
            }
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> min_heap(
          cmp);
        for (auto i = lists.size() - 1; 0 <= i && i < lists.size(); i--) {
            if (!lists[i]) {
                continue;
            }
            min_heap.push(lists[i]);
        }
        ListNode dummy(INT_MIN);
        ListNode* tail = &dummy;
        while (!min_heap.empty()) {
            ListNode* curr = min_heap.top();
            min_heap.pop();

            tail->next = curr;
            tail = tail->next;

            if (tail->next) {
                min_heap.push(tail->next);
            }
        }
        return dummy.next;
    }
};