/*
Approach: Reverse Number Using Recursion

We recursively reverse the digits of the number and compare with the original.

To reverse:
    rev = rev * 10 + n % 10

Base Case:
- If n becomes 0, return the reversed number.

Time Complexity: O(log10(n))
- One call per digit.

Space Complexity: O(log10(n))
*/

#include <iostream>
using namespace std;

int reverseNum(int n, int rev = 0) {
    if (n == 0) return rev;
    return reverseNum(n / 10, rev * 10 + n % 10);
}

bool isPalindrome(int n) {
    return n == reverseNum(n);
}
