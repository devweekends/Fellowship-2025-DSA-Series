/*
Approach: Recursive Power Function

We use the relation:
    power(a, b) = a * power(a, b - 1)
Base Case:
    power(a, 0) = 1

Time Complexity: O(b)

Space Complexity: O(b)
- Each call reduces b by 1 until 0.
*/

#include <iostream>
using namespace std;

int power(int a, int b) {
    if (b == 0) return 1;
    return a * power(a, b - 1);
}
