#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------
🔹 Problem: Count Total Digits in a Number
---------------------------------------------------
Goal: Extract digits of a number and count how many digits it has.

✅ Example:
Input: 1234  
Digits: 1, 2, 3, 4  
Output: 4 (There are 4 digits)
---------------------------------------------------
*/

/*
🔸 Approach: Using Modulo (%) and Division (/)
- Use %10 to get the last digit (rightmost digit)
- Divide by 10 to remove the last digit
- Repeat until number becomes 0
*/

int digitCount(int n) {
    int cnt = 0;
    while (n > 0) {
        int lastDigit = n % 10;
        cnt++;
        n = n / 10;
    }
    return cnt;
}

int main() {
    cout << "Enter a number: ";
    int num;
    cin >> num;

    cout << "Total digits in " << num << " = " << digitCount(num) << endl;

    return 0;
}
