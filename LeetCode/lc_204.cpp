/*
Title: Count Primes

Description:
Count the number of prime numbers less than a non-negative number, n.

Example:
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/

class Solution {
private:
public:
    int countPrimes(int n) {
        if (n < 2) {
            return 0;
        }
        bool* is_prime = new bool[n + 10];
        fill(is_prime, is_prime + n + 9, true);
        vector<int> prime;
        is_prime[0] = false;
        is_prime[1] = false;
        for (int i = 2; i < n; i++) {
            if (is_prime[i]) {
                prime.push_back(i);
            }
            for (int k = 0; k < prime.size() && i * prime[k] < n; k++) {
                is_prime[prime[k] * i] = false;
                if (i % prime[k] == 0) {
                    break;
                }
            }
        }
        delete[] is_prime;
        return prime.size();
    }
};