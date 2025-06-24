/*
Approach: Recursive (Brute Force)

This solution uses a simple recursive approach to compute the nth Fibonacci number.
The Fibonacci sequence is defined as:
    fib(0) = 0
    fib(1) = 1
    fib(n) = fib(n - 1) + fib(n - 2) for n > 1

The function calls itself for the two preceding numbers until it reaches the base cases (n = 0 or n = 1).

Time Complexity: O(2^n)
- This is because the function makes two recursive calls for each non-base case,
  leading to an exponential growth in calls.

Space Complexity: O(n)
- Due to the function call stack in recursion which can go up to n levels deep.

Note:
- This approach is simple but inefficient for large values of n.
- It can be optimized using memoization or iteration to achieve O(n) time complexity.
*/

#include <iostream>
using namespace std;

int fib(int n) {
    if (n <= 1){
        return n;
    }
    return fib(n - 2) + fib(n - 1);
}
