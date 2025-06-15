#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
🔹 Problem: Print All Divisors of a Number
---------------------------------------------------------
Definition: A divisor of a number `n` is any number that divides `n` exactly (i.e., with remainder 0).
Example: For n = 36, divisors are:
1, 2, 3, 4, 6, 9, 12, 18, 36
---------------------------------------------------------
*/

// 🔸 Approach 1: Brute Force
// Loop through all numbers from 1 to n and check if they divide n
void printAllDivisorsBrute(int n) {
    cout << "Brute Force Divisors: ";
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// 🔸 Approach 2: Optimized Square Root Approach
// Divisors occur in pairs (i, n/i), and we only need to loop till sqrt(n)
void printAllDivisorsOptimized(int n) {
    cout << "Optimized (sqrt) Divisors: ";
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cout << i << " ";
            if (i != n / i) { // Avoid duplicate if n is a perfect square
                cout << n / i << " ";
            }
        }
    }
    cout << endl;
}

// 🔸 Approach 3: Using a Vector + Sorting
// Collect divisors in a vector and sort them for ordered output
void printAllDivisorsSorted(int n) {
    cout << "Sorted Divisors: ";
    vector<int> divisors;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    for (int d : divisors) {
        cout << d << " ";
    }
    cout << endl;
}

// 🔸 Approach 4: Recursive Method
// Recursively check and print divisors from 1 to n
void printAllDivisorsRecursiveHelper(int n, int i) {
    if (i > n) return;
    if (n % i == 0) cout << i << " ";
    printAllDivisorsRecursiveHelper(n, i + 1);
}

void printAllDivisorsRecursive(int n) {
    cout << "Recursive Divisors: ";
    printAllDivisorsRecursiveHelper(n, 1);
    cout << endl;
}

// 🔹 Driver Code
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    printAllDivisorsBrute(num);
    printAllDivisorsOptimized(num);
    printAllDivisorsSorted(num);
    printAllDivisorsRecursive(num);

    return 0;
}
