/*
题目：合并两个排序的链表

题目描述：
输入两个单调递增的链表，输出两个链表合成后的链表，
当然我们需要合成后的链表满足单调不减规则。
*/

/*
struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
                        val(x), next(NULL) {
        }
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        /*
        // 迭代解法
        ListNode* l1 = pHead1;
        ListNode* l2 = pHead2;
        ListNode temp(-1);
        ListNode* head = &temp;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                head->next = l2;
                l2 = l2->next;
            } else {
                head->next = l1;
                l1 = l1->next;
            }
            head = head->next;
        }
        head->next = (l1 == nullptr) ? l2 : l1;
        return temp.next;
        */
        // 递归解法
        ListNode* l1 = pHead1;
        ListNode* l2 = pHead2;
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }

        ListNode* head;
        if (l1->val > l2->val) {
            l2->next = Merge(l1, l2->next);
            head = l2;
        } else {
            l1->next = Merge(l1->next, l2);
            head = l1;
        }

        return head;
    }
};
