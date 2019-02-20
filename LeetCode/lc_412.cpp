/*
Title: Fizz Buzz

Description:
Write a program that outputs the string representation of numbers from 1 to n.
But for multiples of three it should output “Fizz” instead of the number and for the
multiples of five output “Buzz”. For numbers which are multiples of both three and five
output “FizzBuzz”.

Example:
n = 15,
Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for (int i = 1; i <= n; i++) {
            string str = "";
            if (i % 3 && i % 5) {
                str += to_string(i);
            } else {
                if (i % 3 == 0) {
                    str += "Fizz";
                }
                if (i % 5 == 0) {
                    str += "Buzz";
                }
            }
            result.push_back(str);
        }
        return result;
    }
};