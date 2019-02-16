/*
题目：删除链表中重复的结点

题目描述：
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
例如，链表1->2->3->3->4->4->5，处理后为 1->2->5。
*/

/*
struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x)
      : val(x)
      , next(NULL) {}
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head) {
        ListNode dummy(0xFFFFFFFF);
        dummy.next = head;
        head = &dummy;
        if (!head->next) {
            return nullptr;
        }
        ListNode *slow = head->next, *fast = slow->next;
        ListNode* slow_prev = head;
        while (fast) {
            while (fast && fast->val == slow->val) {
                fast = fast->next;
            }
            if (slow->next != fast) {
                while (slow != fast) {
                    slow = slow->next;
                    delete slow_prev->next;
                    slow_prev->next = slow;
                }
            } else {
                slow_prev = slow;
                slow = fast;
                if (fast) {
                    fast = fast->next;
                }
            }
        }

        return head->next;
    }
};