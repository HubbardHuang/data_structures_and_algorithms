/*
题目：二维数组中的查找

题目描述：
在一个二维数组中（每个一维数组的长度相同），
每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。
请完成一个函数，
输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

class Solution {
public:
    bool Find(int target, vector<vector<int>> array) {
        int row = 0;
        int column = 0;
        for (row = array.size() - 1; 0 <= row && column < array[0].size();) {
            if (target == array[row][column]) {
                return true;
            } else if (target > array[row][column]) {
                ++column;
            } else if (target < array[row][column]) {
                --row;
            }
        }
        return false;
    }
};