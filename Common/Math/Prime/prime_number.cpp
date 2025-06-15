#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------
🔸 Approach 1: Brute Force
- Check all numbers from 2 to n-1
- If any divides n evenly, it is not prime
- Simple but slow for large n
---------------------------------------------------
*/
bool isPrimeBruteForce(int n) {
    if (n <= 1) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}


/*
---------------------------------------------------
🔸 Approach 2: Optimized Check (Up to √n)
- If n has a factor larger than √n,
  then it must have one smaller too
- We only check up to sqrt(n)
- Much faster for large numbers
---------------------------------------------------
*/
bool isPrimeOptimized(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}


/*
---------------------------------------------------
🔸 Approach 3: Recursive Prime Checker
- Recursively check from i = 2 to √n
- If n is divisible by any i, it is not prime
- Educational, less efficient than loops
---------------------------------------------------
*/

// Helper function with divisor `i`
bool isPrimeRecursive(int n, int i) {
    if (i * i > n) return true;
    if (n % i == 0) return false;
    return isPrimeRecursive(n, i + 1);
}

// Main recursive function
bool isPrimeRecursive(int n) {
    if (n <= 1) return false;
    return isPrimeRecursive(n, 2);
}
