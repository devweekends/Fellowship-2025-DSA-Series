#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------------
🔹 Problem: Find the GCD (Greatest Common Divisor) of Two Numbers
------------------------------------------------------------
Also called HCF (Highest Common Factor). It is the largest number
that divides both given numbers exactly (without remainder).

✅ Example:
Input: 20, 15  
Output: 5  
Explanation: 5 is the largest number that divides both 20 and 15.
------------------------------------------------------------
*/


// 🔸 Approach 1: Brute Force Method
/*
Loop from 1 to min(n1, n2) and check for all numbers that divide both.
Track the largest such number.

🧠 Logic:
- Start with hcf = 1
- For each i from 1 to min(n1, n2):
    - If both n1 and n2 are divisible by i → update hcf

📈 Time Complexity: O(min(n1, n2))
*/
void gcdBruteForce(int n1, int n2) {
    int hcf = 1;
    for (int i = 1; i <= min(n1, n2); i++) {
        if (n1 % i == 0 && n2 % i == 0) {
            hcf = i;
        }
    }
    cout << "GCD (Brute Force): " << hcf << endl;
}


// 🔸 Approach 2: Euclidean Algorithm
/*
Efficient method using modulo (%).
Key Property: gcd(a, b) = gcd(b, a % b)

Repeat until one number becomes 0.
The other number will be the GCD.

📈 Time Complexity: O(log(min(a, b)))
*/
int gcdEuclidean(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return (a == 0) ? b : a;
}


// 🔹 Driver Code
int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    gcdBruteForce(a, b);
    cout << "GCD (Euclidean): " << gcdEuclidean(a, b) << endl;

    return 0;
}
