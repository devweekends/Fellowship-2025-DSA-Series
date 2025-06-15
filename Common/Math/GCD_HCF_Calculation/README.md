# 🔗 GCD / HCF of Two Numbers — C++ Implementation

---

## 📘 Problem Statement

You are given two integers `a` and `b`.  
Your task is to compute their **GCD (Greatest Common Divisor)**, which is also called **HCF (Highest Common Factor)**.

> ✅ GCD is the largest number that divides both `a` and `b` without leaving a remainder.

---

## ✳️ Example

Input: 20, 15
Divisors of 20 → 1, 2, 4, 5, 10, 20
Divisors of 15 → 1, 3, 5, 15
Common Divisors → 1, 5
GCD = 5


---

## 🚀 Approaches

### 🔸 1. Brute Force

- Loop from 1 to `min(a, b)`
- Check if the number divides both `a` and `b`
- Keep updating the largest such number

#### ⏱️ Time Complexity:
- O(min(a, b))

#### ✅ Usage:
Good for small values or when learning the basics.

---

### 🔸 2. Euclidean Algorithm

Uses the fact that:
gcd(a, b) = gcd(b, a % b)



- Repeat until one of the numbers becomes 0
- The other number is the result

#### ⏱️ Time Complexity:
- O(log(min(a, b)))

#### ✅ Usage:
Efficient and used in real-world applications, competitive coding, cryptography, etc.

---

## 📂 File Structure

GCD_HCF_Calculations/
├── gcd.cpp # Full C++ source with both methods
├── README.md # Explanation and documentation
├── Makefile # Build and run commands