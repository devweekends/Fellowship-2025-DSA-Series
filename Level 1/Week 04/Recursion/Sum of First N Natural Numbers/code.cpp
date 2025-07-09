
/*
Approach: Recursive Summation

We recursively add the current number to the result of the sum of numbers before it.
    sum(n) = n + sum(n - 1)

Base Case:
- sum(0) = 0

Time Complexity: O(N)
- One call per number from N down to 0.

Space Complexity: O(N)
- Due to call stack depth.
*/

#include <iostream>
using namespace std;

int sum(int n) {
    if (n == 0) return 0;
    return n + sum(n - 1);
}
