/*
题目：反转链表

题目描述：
输入一个链表，反转链表后，输出新链表的表头。
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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* prev = nullptr;
        ListNode* curr = pHead;
        ListNode* next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
