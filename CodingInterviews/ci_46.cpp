/*
题目：约瑟夫环

题目描述：
已知n个人（以编号0，1，2，3...n-1分别表示）围坐在一张圆桌周围。
从编号为0的人开始报数，数到m的那个人出列；
他的下一个人又从1开始报数，数到m的那个人又出列；
依此规律重复下去，直到圆桌周围的人全部出列。
求最后出列的玩家编号。
*/

class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        // // 法一，用链表模拟整个过程
        // list<int> children;
        // for (int i = 0; i < n; i++) {
        //     children.push_back(i);
        // }
        // if (children.empty()) {
        //     return -1;
        // }
        // int final_child = -1;
        // auto selected_child = children.begin();
        // bool first = true;
        // while (!children.empty()) {
        //     for (int i = 0; i < m; i++) {
        //         if (!first) {
        //             selected_child++;
        //             if (selected_child == children.end()) {
        //                 selected_child = children.begin();
        //             }
        //         }
        //         first = false;
        //     }
        //     final_child = *selected_child;
        //     auto temp = selected_child;
        //     ++selected_child;
        //     if (selected_child == children.end()) {
        //         selected_child = children.begin();
        //     }
        //     children.erase(temp);
        //     first = true;
        // }
        // return final_child;

        // 法二，使用递推公式 f(i) = (f(i - 1) + m) % i, i > 1
        if (n <= 0) {
            return -1;
        }
        if (n == 1) {
            return 0;
        }
        int result = 0;
        for (int i = 2; i <= n; i++) {
            result = (result + m) % i;
        }
        return result;
    }
};