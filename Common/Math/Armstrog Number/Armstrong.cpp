#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------
🔹 Approach 1: Iterative with Full If-Else
- Extracts each digit
- Cubes it and adds to sum
- Compares sum to original number
- Uses if-else for return
------------------------------------------
*/
int isArmstrong(int n) {
    int rev_num = 0;
    int N = n;
    while (n > 0) {
        int last_digit = n % 10;
        rev_num += (last_digit * last_digit * last_digit);
        n /= 10;
    }
    if (N == rev_num) {
        return true;
    } else {
        return false;
    }
}

/*
------------------------------------------
🔹 Approach 2: Iterative with Cleaner Return
- Same logic as Approach 1
- Directly returns boolean condition
- More concise and readable
------------------------------------------
*/
int isArmstrong(int n) {
    int rev_num = 0;
    int N = n;
    while (n > 0) {
        int last_digit = n % 10;
        rev_num += (last_digit * last_digit * last_digit);
        n /= 10;
    }
    return N == rev_num;
}

/*
------------------------------------------
🔹 Approach 3: Recursive
- Calculates sum of digits raised to total digit count
- Uses recursion for summation
- log10(n) + 1 to find number of digits
------------------------------------------
*/
int sumOfPowers(int n, int digits) {
    if (n == 0) return 0;
    int digit = n % 10;
    return pow(digit, digits) + sumOfPowers(n / 10, digits);
}

bool isArmstrong1(int n) {
    int digits = log10(n) + 1;
    return n == sumOfPowers(n, digits);
}

/*
------------------------------------------
🔹 Approach 4: String-based
- Converts number to string to count digits
- Uses char iteration to extract digits
- Applies pow() to each digit
------------------------------------------
*/
#include <cmath>
#include <string>
bool isArmstrong2(int n) {
    string str = to_string(n);
    int digits = str.size();
    int sum = 0;
    for (char c : str) {
        int digit = c - '0';
        sum += pow(digit, digits);
    }
    return sum == n;
}

/*
------------------------------------------
🔹 Approach 5: Precomputed Powers (Efficient)
- Calculates pow(i, digits) for digits 0–9 once
- Avoids repeated calls to pow() in loop
- Much faster for large-scale checks
------------------------------------------
*/
#include <cmath>
bool isArmstrong3(int n) {
    int original = n;
    int sum = 0;
    int digits = log10(n) + 1;

    int power[10];
    for (int i = 0; i < 10; i++) {
        power[i] = pow(i, digits);
    }

    while (n > 0) {
        int digit = n % 10;
        sum += power[digit];
        n /= 10;
    }
    return sum == original;
}
