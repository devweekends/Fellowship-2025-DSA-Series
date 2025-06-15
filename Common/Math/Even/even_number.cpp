#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------
🔹 Approach 1: Modulo Operator (%)
- If a number divided by 2 has no remainder,
  it is even.
- Classic and most readable method.
------------------------------------------
*/
bool even(int n) {
    return n % 2 == 0;
}

/*
------------------------------------------
🔹 Approach 2: Bitwise AND Operator (&)
- Binary trick: even numbers have 0 as the last bit.
- Checking (n & 1) gives 0 if it's even.
- Very efficient.
------------------------------------------
*/
bool even_bitwise(int n) {
    return (n & 1) == 0;
}

/*
------------------------------------------
🔹 Approach 3: Integer Division Trick
- Divide the number by 2 and multiply it back.
- If the result equals original number, it's even.
- Uncommon but clever.
------------------------------------------
*/
bool even_division(int n) {
    return (n / 2) * 2 == n;
}

/*
------------------------------------------
🔹 Approach 4: Recursive Method
- Subtract 2 recursively until 0 or 1.
- Base Case: 0 = even, 1 = odd.
- Great for learning recursion but not optimal.
------------------------------------------
*/
bool even_recursive(int n) {
    if (n == 0) return true;
    if (n == 1) return false;
    return even_recursive(n - 2);
}
