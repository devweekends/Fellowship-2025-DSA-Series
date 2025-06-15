#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------
🔹 Approach 1: Modulo Operator (%)
- If a number divided by 2 leaves remainder 1,
  it's odd.
- Straightforward and easy to understand.
------------------------------------------
*/
bool odd(int n) {
    return n % 2 == 1;
}

/*
------------------------------------------
🔹 Approach 2: Bitwise AND Operator (&)
- Odd numbers have 1 as the last binary digit.
- So, if (n & 1) == 1, it's odd.
- Fast and efficient.
------------------------------------------
*/
bool odd_bitwise(int n) {
    return (n & 1) != 0;
}

/*
------------------------------------------
🔹 Approach 3: Integer Division
- Divide the number by 2 and multiply it back.
- If the result is not equal to original,
  it's odd.
------------------------------------------
*/
bool odd_division(int n) {
    return (n / 2) * 2 != n;
}

/*
------------------------------------------
🔹 Approach 4: Recursive Method
- Base case: 0 → false (even), 1 → true (odd)
- Reduce n by 1 each time to reach the base case.
- Helps understand recursion.
------------------------------------------
*/
bool odd_recursive(int n) {
    if (n == 0) return false;
    if (n == 1) return true;
    return odd_recursive(n - 2);
}
