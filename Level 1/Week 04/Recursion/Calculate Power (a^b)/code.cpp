/*
Approach: Optimized Recursive Power Function (Exponentiation by Squaring)

We use:
    power(a, b) = power(a * a, b / 2)      if b is even
    power(a, b) = a * power(a * a, b / 2)  if b is odd
Base Case:
    power(a, 0) = 1

Time Complexity: O(log b)
Space Complexity: O(log b)
*/

#include <iostream>
using namespace std;

int power(int a, int b) {
    if (b == 0) return 1;

    int half = power(a, b / 2);

    if (b % 2 == 0)
        return half * half;
    else
        return a * half * half;
}
