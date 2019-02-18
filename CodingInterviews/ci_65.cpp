/*
题目：矩阵中的路径

题目描述：
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。
例如 a b c e s f c s a d e e 这样的 3 X 4 矩阵中，
包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/

class Solution {
private:
    bool BfsRecursively(vector<vector<char>>& buffer, int row, int col,
                        const string& target, int index) {
        bool result = false;
        if (target[index] == buffer[row][col]) {
            if (index == target.size() - 1) {
                return true;
            }
            char temp = buffer[row][col];
            buffer[row][col] = 0;
            if (row + 1 < buffer.size() && buffer[row + 1][col] != 0) {
                result |= BfsRecursively(buffer, row + 1, col, target, index + 1);
            }
            if (row - 1 >= 0 && buffer[row - 1][col] != 0) {
                result |= BfsRecursively(buffer, row - 1, col, target, index + 1);
            }
            if (col + 1 < buffer[0].size() && buffer[row][col + 1] != 0) {
                result |= BfsRecursively(buffer, row, col + 1, target, index + 1);
            }
            if (col - 1 >= 0 && buffer[row][col - 1] != 0) {
                result |= BfsRecursively(buffer, row, col - 1, target, index + 1);
            }
            buffer[row][col] = temp;
        }
        return result;
    }
    bool BFS(vector<vector<char>>& buffer, const string& target) {
        // 查找 target[i] 在 buffer 中的位置
        int row = buffer.size();
        int col = buffer[0].size();
        bool result = false;
        for (int i = 0; i < row; i++) {
            for (int k = 0; k < col; k++) {
                result = BfsRecursively(buffer, i, k, target, 0);
                if (result == true) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool hasPath(char* matrix, int rows, int cols, char* str) {
        string target(str);
        if (target.size() == 0) {
            return false;
        }
        vector<vector<char>> buffer(rows);
        for (int i = 0; i < rows; i++) {
            buffer[i].resize(cols);
            for (int k = 0; k < cols; k++) {
                buffer[i][k] = matrix[i * cols + k];
            }
        }

        return BFS(buffer, target);
    }
};