/*
题目：链表中倒数第k个结点

题目描述：
输入一个链表，输出该链表中倒数第k个结点。
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == nullptr) {
            return nullptr;
        }
        ListNode* behind = pListHead;
        ListNode* front = behind;
        int i;
        for (i = 0; i < k && front != nullptr; i++) {
            front = front->next;
        }
        if (i != k) {
            return nullptr;
        }
        while (front != nullptr) {
            behind = behind->next;
            front = front->next;
        }
        return behind;
    }
};