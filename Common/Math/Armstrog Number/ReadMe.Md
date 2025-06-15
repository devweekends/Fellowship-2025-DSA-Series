# 🔢 Armstrong Number – C++ Solutions

### 💡 What is an Armstrong Number?

An **Armstrong number** (also called a **narcissistic number**) is a number that is equal to the **sum of its own digits each raised to the power of the number of digits**.

Let’s break that down simply:

👉 Take any number — say, **153**

- It has 3 digits.
- Now, raise each digit to the power of 3:
  - \(1^3 = 1\)
  - \(5^3 = 125\)
  - \(3^3 = 27\)
- Add them: \(1 + 125 + 27 = 153\)

Since the sum equals the original number, **153 is an Armstrong number!**

🔹 Another example:
**9474**
- \(9^4 + 4^4 + 7^4 + 4^4 = 9474\)
✅ It's an Armstrong number too!

---

## 📘 What’s Covered in This File?

This program showcases **five different ways** to check if a number is an Armstrong number in C++:

| Approach | Description |
|---------|-------------|
| 1 | Classic method using a `while` loop and manual cube calculation |
| 2 | Simplified version using a direct boolean return |
| 3 | **Recursive** approach using `pow()` |
| 4 | **String-based** method for digit extraction |
| 5 | **Optimized** version using precomputed powers |

---

## 🧠 Why So Many Approaches?

Each version teaches you something new:

- 🔁 Loops and conditions  
- 🔙 Recursion  
- 🧮 Working with digits  
- 💨 Optimization techniques  
- 🔤 String manipulation

---

## 🗂 File Structure

- `Armstrong.cpp` 

---

## 🔍 Sample Usage

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 153;
    if (isArmstrong(n)) {
        cout << n << " is an Armstrong number.\n";
    } else {
        cout << n << " is not an Armstrong number.\n";
    }

    // Similarly, test other versions:
    // isArmstrong1(n), isArmstrong2(n), isArmstrong3(n)
}
