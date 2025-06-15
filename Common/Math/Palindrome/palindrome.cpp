#include <bits/stdc++.h>
using namespace std;

// 🔸 Approach 1: Reverse Integer and Compare
bool isPalindromeNumber1(int n) {
    int rev = 0, original = n;
    while (n > 0) {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    }
    return rev == original;
}

// 🔸 Approach 2: String-Based Two Pointers
bool isPalindromeNumber2(int n) {
    string s = to_string(n);
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}

// 🔸 Approach 3: Recursive Reverse Comparison
bool helper(int n, int &temp) {
    if (n == 0) return true;
    if (!helper(n / 10, temp)) return false;
    if ((n % 10) != (temp % 10)) return false;
    temp /= 10;
    return true;
}

bool isPalindromeNumber3(int n) {
    if (n < 0) return false;
    int temp = n;
    return helper(n, temp);
}

// ------------------------------------------------------------
// Array-Based Palindrome Check
// ------------------------------------------------------------

// 🔸 Approach 1: Two-Pointer Technique
bool isPalindromeArray1(const vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        if (arr[left++] != arr[right--])
            return false;
    }
    return true;
}

// 🔸 Approach 2: Reverse and Compare
bool isPalindromeArray2(const vector<int>& arr) {
    vector<int> reversed = arr;
    reverse(reversed.begin(), reversed.end());
    return arr == reversed;
}

// 🔸 Approach 3: Recursive Check
bool isPalindromeArrayRecursive(const vector<int>& arr, int l, int r) {
    if (l >= r) return true;
    if (arr[l] != arr[r]) return false;
    return isPalindromeArrayRecursive(arr, l + 1, r - 1);
}
bool isPalindromeArray3(const vector<int>& arr) {
    return isPalindromeArrayRecursive(arr, 0, arr.size() - 1);
}

// 🔸 Approach 4: Compare First Half with Second Half
bool isPalindromeArray4(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - i - 1]) return false;
    }
    return true;
}
