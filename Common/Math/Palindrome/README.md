# 🔁 Palindrome Checker – Numbers & Arrays in C++

---

## 📘 Problem Statement

A **palindrome** is a number or sequence that reads the same backward as forward.

---

## ✳️ Examples:

- **Numbers:**
  - ✅ 121 → Palindrome
  - ❌ 123 → Not Palindrome
- **Arrays:**
  - ✅ [1, 2, 3, 2, 1]
  - ❌ [1, 2, 3, 4]

---

## 🚀 Approaches

### 🔢 For Numbers:

| Approach         | Description                                       |
|------------------|---------------------------------------------------|
| Reverse Method   | Reverse number and compare with original          |
| String Method    | Convert to string and use two pointers            |
| Recursive Method | Recursively reverse & compare digits              |

---

### 🧮 For Arrays:

| Approach          | Description                                            |
|-------------------|--------------------------------------------------------|
| Two Pointers      | Compare start and end until middle                    |
| Reverse & Compare | Reverse copy and check equality                       |
| Recursive         | Recursively compare from both ends                    |
| Half Comparison   | Loop over first half and compare with second half     |

---

## 🧠 Why So Many Approaches?

Different problems may restrict:
- Space (avoid reversing)
- Performance (prefer recursion or two-pointers)
- Language features (e.g., `string`, `reverse()`)

---

## 📂 File Structure

PalindromeCheck/
├── palindrome_number_array.cpp # C++ source file with all implementations
├── README.md # Documentation and explanation
└── Makefile # Build and run the code