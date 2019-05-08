/*
Title: Kth Smallest Element in a Sorted Matrix

Description:
Given a n x n matrix
where each of the rows and columns are sorted in ascending order,
find the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order,
not the kth distinct element.

Example:
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
return 13.

Note:
You may assume k is always valid, 1 ≤ k ≤ n*n.
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) {
            return INT_MIN;
        }
        int min = matrix.front().front();
        int max = matrix.back().back() + 1;
        while (min < max) {
            int mid = min + (max - min) / 2;
            int count = 0;
            int col = matrix.front().size() - 1;
            for (int row = 0; row < matrix.size(); row++) {
                while (0 <= col && matrix[row][col] > mid) {
                    col--;
                }
                count += col + 1;
            }
            if (count < k) {
                min = mid + 1;
            } else {
                max = mid;
            }
        }
        return min;
    }
};