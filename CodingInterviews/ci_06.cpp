/*
题目：旋转数组的最小数字

题目描述：
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 0) {
            return 0;
        }

        int cur_pos = 0;
        int next_pos = cur_pos + 1;
        for (; next_pos < rotateArray.size(); next_pos++) {
            if (rotateArray[cur_pos] > rotateArray[next_pos]) {
                return rotateArray[next_pos];
            }
        }
        return rotateArray[0];
    }
};