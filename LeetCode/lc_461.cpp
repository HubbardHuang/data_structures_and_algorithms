/*
Title: Hamming Distance

Description:
The Hamming distance between two integers is the number
of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 2^31.

Example:
Input: x = 1, y = 4

Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int xy_xor = x ^ y;

        // Count number of '1' in [xy_xor]
        int count = 0;
        while (xy_xor) {
            xy_xor &= (xy_xor - 1);
            ++count;
        }
        return count;
    }
};