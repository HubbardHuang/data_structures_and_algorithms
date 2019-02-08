/*
题目：两个链表的第一个公共结点

题目描述：
输入两个链表，找出它们的第一个公共结点。
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
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1 || !pHead2) {
            return nullptr;
        }
        ListNode* h1 = pHead1;
        ListNode* h2 = pHead2;
        while (h1 != h2) {
            h1 = (h1 == nullptr) ? pHead1 : h1->next;
            h2 = (h2 == nullptr) ? pHead2 : h2->next;
        }
        return h1;
    }
};