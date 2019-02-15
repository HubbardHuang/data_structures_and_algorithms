/*
题目：链表中环的入口结点

题目描述：
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
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
    ListNode* EntryNodeOfLoop(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        if (!fast || !fast->next) {
            return nullptr;
        }

        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};