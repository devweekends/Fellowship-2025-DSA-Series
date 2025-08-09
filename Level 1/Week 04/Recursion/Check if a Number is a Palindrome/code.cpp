/*
✅ Problem :
Check whether a given integer is a palindrome.

A palindrome is a number that reads the same forward and backward.
Examples:
- 121 → true
- 123 → false
- -121 → false (negative numbers are not palindromes)

Constraints:
- Negative numbers are not palindromes.
- Numbers ending in 0 (but not 0 itself) are not palindromes.

---

✅ Approach: Reverse Number Using Recursion

We recursively reverse the digits of the number and compare with the original.

To reverse:
    rev = rev * 10 + (n % 10)

Steps:
1. Base Case: if n == 0 → return the reversed number.
2. Otherwise:
   - Extract last digit using % 10.
   - Remove last digit using / 10.
   - Build reversed number step-by-step.

Edge Cases:
- n < 0 → not a palindrome
- Ends with 0 but is not 0 → not a palindrome (e.g., 10, 100)

Example Dry Run for n = 121:
    reverse(121) = reverse(12, 1)
                 = reverse(1, 12)
                 = reverse(0, 121)
                 → returns 121 → equal to original → palindrome

---

⏱️ Time Complexity: O(log₁₀(n)) 
    - One recursive call per digit in the number.

📦 Space Complexity: O(log₁₀(n)) 
    - Due to recursion stack (one frame per digit).
*/


// ✅ important Concept Understanding – Behind the Scenes Digit Handling:

// 👉 How to get the last digit of a number:
//     71 % 10 = 1
//     Visual:
//     10 | 71
//        | 70   → remainder is 1 → last digit
//     ✔️ So, x % 10 gives us the **last digit** of x

// 👉 How to remove the last digit from a number (pop operation):
//     71 / 10 = 7
//     Visual:
//     10 | 71
//        | 70
//         ---
//           1 → ignore remainder, result is 7
//     ✔️ So, x / 10 removes the **last digit** of x

// 👉 How to add a digit at the end of a number (push operation):
//     If we have 7 and want to add 1 at the end:
//     7 * 10 = 70 → then 70 + 1 = 71
//     ✔️ So, to "push" a digit to the right → x * 10 + digit


   

//  With Recursion  we learn recursion so we folllow another approch below which is only for practice 
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) 
            return false;

        return x == reverse(x);
    }

private:
    long long reverse(int remainingleft, long long right = 0)
    {
        if (remainingleft == 0) 
            return right;

        int ri = remainingleft % 10;
        int left = remainingleft / 10;

        return reverse(left, right * 10 + ri);
    }
};




// ✅ Approach 2: Without Recursion (Optimized) but we learn recursion 
// Reverses only half of the number and compares with the remaining half.
// This avoids overflow and reduces operations.

// class Solution {
// public:
//     bool isPalindrome(int x) {
//         // Check for invalid cases: negative number or number ending in 0 (except 0)
//         if (x < 0 || (x % 10 == 0 && x != 0))
//             return false;

//         int reversedHalf = 0;

//         // Keep reversing digits until reversedHalf ≥ x (i.e., half the number)
//         while (reversedHalf < x) {
//             int lastDigit = x % 10;  // Get the last digit
//             reversedHalf = reversedHalf * 10 + lastDigit;  // Append to reversedHalf
//             x = x / 10;  // Remove last digit from x
//         }

//         // For even-length numbers: both halves should match
//         // For odd-length numbers: ignore middle digit by reversedHalf / 10
//         return x == reversedHalf || x == reversedHalf / 10;
//     }
// };
