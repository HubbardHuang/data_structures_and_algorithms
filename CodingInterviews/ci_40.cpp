/*
题目：数组中只出现一次的数字

题目描述：
一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。
请写程序找出这两个只出现一次的数字。
*/

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
        int xor_result = 0;
        for (auto i = data.begin(); i != data.end(); i++) {
            xor_result ^= *i;
        }

        int first_one_index = 0;
        for (int i = 0; i < sizeof(int) * 8; i++) {
            if ((xor_result & (1 << i)) != 0) {
                first_one_index = i;
                break;
            }
        }

        // // 化解成“只有一个数字出现了一次，其余都出现了偶数次”的问题
        // *num1 = 0;
        // *num2 = 0;
        // for (auto i = data.begin(); i != data.end(); i++) {
        //     if (((*i) & (1 << first_one_index)) != 0) {
        //         (*num1) ^= (*i);
        //     } else {
        //         (*num2) ^= (*i);
        //     }
        // }

        // 利用异或运算性质——若 a^b=c，则 c^b=a，c^a=b
        int result1, result2;
        result1 = result2 = xor_result;
        for (auto i = data.begin(); i != data.end(); i++) {
            if (((*i) & (1 << first_one_index)) != 0) {
                result1 ^= (*i);
            } else {
                result2 ^= (*i);
            }
        }
        *num1 = result1;
        *num2 = result2;
    }
};