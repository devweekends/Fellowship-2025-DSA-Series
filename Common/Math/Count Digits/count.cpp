#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------
🔸 Approach 1: Brute Force using Modulo
- Loop through each digit using modulo
- Check if digit != 0 and divides original number
---------------------------------------------------
*/
int evenDigits(int n) {
    int cnt = 0;
    int N = n; // Store original number

    while (n > 0) {
        int digit = n % 10;
        n /= 10;

        if (digit != 0 && N % digit == 0) {
            cnt++;
        }
    }
    return cnt;
}

/*
---------------------------------------------------
🔸 Approach 2: Count Total Digits Using log10
- Just counts total digits, not the ones that divide
- Use: log10(num) + 1
- Not relevant to "divisible digits" but useful
---------------------------------------------------
*/
int totalDigits(int num) {
    if (num == 0) return 1;
    return (int)(log10(num) + 1);
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    cout << "Number of digits in " << number << " that divide it evenly: "
         << evenDigits(number) << endl;

    cout << "Total number of digits in " << number << ": "
         << totalDigits(number) << endl;

    return 0;
}
