/*
Title: Pascal's Triangle

Description:
Given a non-negative integer numRows,
generate the first numRows of Pascal's triangle.
In Pascal's triangle,
each number is the sum of the two numbers directly above it.

Example:
Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0) {
            return result;
        }
        for (int i = 0; i < numRows; i++) {
            vector<int> one_row(i + 1);
            one_row[0] = 1;
            for (int k = 1; k < i; k++) {
                one_row[k] = result[i - 1][k] + result[i - 1][k - 1];
            }
            one_row[i] = 1;
            result.push_back(one_row);
        }
        return result;
    }
};