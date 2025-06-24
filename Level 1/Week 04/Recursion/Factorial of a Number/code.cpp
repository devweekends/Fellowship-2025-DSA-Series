/*
Approach: Recursive (Simple Reverse Counting)

This function prints numbers from N to 1 using recursion.
It starts from N and decreases the number by one at each step.

Base Case:
- If the current number becomes less than 1, we stop recursion.

Time Complexity: O(N)
- We print N numbers once.

Space Complexity: O(N)
- Due to recursive calls up to N levels deep.
*/

#include <iostream>
using namespace std;

void printNTo1(int n) {
    if (n < 1) return;
    cout << n << " ";
    printNTo1(n - 1);
}
