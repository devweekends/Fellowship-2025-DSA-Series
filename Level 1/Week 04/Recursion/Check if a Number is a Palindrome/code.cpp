/*
Approach: Recursive Factorial

The factorial of a number n is:
    n! = n * (n - 1)!

We use recursion to multiply n with the factorial of (n - 1),
until we reach the base case:
    0! = 1

Time Complexity: O(N)

Space Complexity: O(N)
- Due to the function call stack.
*/

#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
