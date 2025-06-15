#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------------
🔹 Problem: Reverse a Number (e.g., 12345 → 54321)
------------------------------------------------------------
The goal is to reverse the digits of a given integer.

Example:
Input: 1234
Output: 4321
------------------------------------------------------------
*/

// 🔸 Approach 1: While Loop (Mathematical)
int reverseNumberLoop(int num) {
    int reversed = 0;
    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return reversed;
}

// 🔸 Approach 2: Recursion
int reverseNumberRecursiveHelper(int num, int reversed = 0) {
    if (num == 0) return reversed;
    return reverseNumberRecursiveHelper(num / 10, reversed * 10 + num % 10);
}

// 🔸 Approach 3: String Reversal
int reverseNumberString(int num) {
    string str = to_string(num);
    std::reverse(str.begin(), str.end());
    return stoi(str);
}

// 🔸 Approach 4: For Loop (Alternative Math)
int reverseNumberForLoop(int num) {
    int reversed = 0;
    for (; num != 0; num /= 10) {
        reversed = reversed * 10 + (num % 10);
    }
    return reversed;
}

// 🔹 Driver Code
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Reversed (While Loop): " << reverseNumberLoop(num) << endl;
    cout << "Reversed (Recursion): " << reverseNumberRecursiveHelper(num) << endl;
    cout << "Reversed (String): " << reverseNumberString(num) << endl;
    cout << "Reversed (For Loop): " << reverseNumberForLoop(num) << endl;

    return 0;
}
