/*
题目：从尾到头打印链表

题目描述：
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*/

/**
 *  struct ListNode {
 *        int val;
 *        struct ListNode *next;
 *        ListNode(int x) :
 *              val(x), next(NULL) {
 *        }
 *  };
 */
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        Recursively(head, result);
        return result;
    }

private:
    void Recursively(ListNode* head, vector<int>& result) {
        if (head == nullptr) {
            return;
        }
        Recursively(head->next, result);
        result.push_back(head->val);
    }
};