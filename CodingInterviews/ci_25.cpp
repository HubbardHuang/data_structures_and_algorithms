/*
题目：复杂链表的复制

题目描述：
输入一个复杂链表（每个节点中有节点值，以及两个指针，
一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x)
      : label(x)
      , next(NULL)
      , random(NULL) {}
};
*/
// 法一，先根据 next 指针复制整个链表，再处理 random 指针
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (!pHead) {
            return pHead;
        }
        RandomListNode *head, *copy_node;
        RandomListNode dummy(-1);
        // 处理 next 指针
        copy_node = &dummy;
        head = pHead;
        while (head) {
            RandomListNode* temp = new RandomListNode(head->label);
            copy_node->next = temp;
            copy_node = copy_node->next;
            head = head->next;
        }
        copy_node = nullptr;
        // 处理 random 指针
        copy_node = dummy.next;
        head = pHead;
        while (head && copy_node) {
            // 计算 pHead 与 head->random 结点距离多少步
            int count = -1;
            bool backward = true;
            if (head->random != nullptr) {
                RandomListNode *start = pHead, *end = head->random;
                for (count = 0; start != end; ++count) {
                    start = start->next;
                }
            }
            // 以 dummy.next 为起点，往前走 count 步，
            // 找到目标结点并将其地址赋给 copy_node->random
            if (count == -1) {
                copy_node->random = nullptr;
            } else {
                RandomListNode* target = dummy.next;
                for (int i = 0; i < count; i++) {
                    target = target->next;
                }
                copy_node->random = target;
            }
            // 迭代
            copy_node = copy_node->next;
            head = head->next;
        }
        return dummy.next;
    }
};
// 法二，先对原链表进行插入操作，将其从 A-B 变成 A-A'-B-B' 的形式，再提取出 A'-B' 并返回
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (!pHead) {
            return pHead;
        }
        RandomListNode* node = nullptr;
        // 插入新结点，(A-B) -> (A-A'-B-B')
        node = pHead;
        while (node) {
            RandomListNode* same_node = new RandomListNode(node->label);
            same_node->next = node->next;
            node->next = same_node;
            node = same_node->next;
        }
        // 处理新插入结点的 random 指针
        node = pHead;
        while (node) {
            RandomListNode* same_node = node->next;
            if (node->random) {
                same_node->random = node->random->next;
            } else {
                same_node->random = nullptr;
            }
            node = same_node->next;
        }
        // 从 (A-A'-B-B') 中提取 (A'-B')
        RandomListNode* ordinary_curr = pHead;
        RandomListNode* new_list = ordinary_curr->next;
        while (ordinary_curr) {
            RandomListNode* new_curr = ordinary_curr->next;
            // 找出下一个结点并串接好原链和新链
            RandomListNode* ordinary_next = new_curr->next;
            RandomListNode* new_next = ordinary_next ? ordinary_next->next : nullptr;
            new_curr->next = new_next;
            ordinary_curr->next = ordinary_next;
            // 迭代
            // new_curr = new_next;
            ordinary_curr = ordinary_next;
        }
        return new_list;
    }
};