/*
题目：构建乘积数组

题目描述：
给定一个数组A[0,1,...,n-1]，请构建一个数组B[0,1,...,n-1]，
B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
不能使用除法。
*/

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int length = A.size();
        vector<int> result;
        if (length == 0) {
            result.clear();
            return result;
        }

        result.push_back(1);
        for (int i = 0; i < length - 1; i++) {
            result.push_back(result.back() * A[i]);
        }
        int temp = 1;
        for (int i = length - 1; i >= 0; i--) {
            result[i] *= temp;
            temp *= A[i];
        }
        return result;
    }
};