/*
Approach: Recursive (Simple Forward Counting)

This function prints numbers from 1 to N using recursion. 
It starts from 1 and goes up by one until it reaches N.

Base Case:
- If the current number exceeds N, we stop the recursion.

Time Complexity: O(N)
- Each number from 1 to N is printed once.

Space Complexity: O(N)
- Due to N recursive calls on the stack.
*/

#include <iostream>
using namespace std;

void print1ToN(int i, int n) {
    if (i > n) return;
    cout << i << " ";
    print1ToN(i + 1, n);
}
