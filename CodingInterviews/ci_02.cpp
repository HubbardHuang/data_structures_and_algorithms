/*
题目：替换空格

题目描述：
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

class Solution {
public:
    void replaceSpace(char* str, int length) {
        // 遍历一次找出空格个数
        int space_num = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ') {
                ++space_num;
            }
        }

        // 推算字符串需要扩展的字符个数
        const char* new_element = "%20";
        int new_element_length = strlen(new_element);
        int difference = new_element_length - 1;
        int rest_space_num = space_num;
        int back_step = space_num * difference;

        // 后退
        char* ptr_origin = str + length;
        char* ptr_new = str + length + back_step;
        while (ptr_origin < ptr_new) {
            if (*ptr_origin == ' ') {
                for (int k = new_element_length; k > 0; k--) {
                    *ptr_new = new_element[k - 1];
                    --ptr_new;
                }
                --ptr_origin;
            } else {
                *ptr_new = *ptr_origin;
                --ptr_new;
                --ptr_origin;
            }
        }
    }
};