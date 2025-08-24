# 🔄 Data Structures Guide: Recursion

This repository contains a comprehensive overview of **Recursion** - a fundamental programming concept where a function calls itself to solve problems by breaking them down into smaller, similar subproblems.

---

## 📑 Table of Contents

- [🧠 General Understanding](#-general-understanding)
- [🌍 Real-Life Analogy](#-real-life-analogy)
- [📘 Recursion](#-recursion)
  - [✅ Key Properties](#key-properties)
  - [💡 When to Use Recursion](#-when-to-use-recursion)
  - [🔄 Recursion Process](#-recursion-process)
  - [🧪 Real-World Examples](#-real-world-examples)
  - [⚠️ Best Practices](#-best-practices)
- [📚 Final Notes](#-final-notes)

---

## 🧠 General Understanding

### Recursion

**Recursion** is a programming technique where a function calls itself to solve a problem. It works by breaking down a complex problem into smaller, simpler subproblems that are solved using the same approach.

---

## 🌍 Real-Life Analogy

Imagine recursion as **Russian nesting dolls**:

- Each doll contains a smaller doll inside
- To see the smallest doll, you must open each outer doll
- The process repeats until you reach the base case (smallest doll)
- Then you work your way back out, understanding the complete structure
- Each level follows the same pattern but with different sizes

---

## 📘 Recursion

Recursion is great when:
- The problem can be **broken down into smaller, similar subproblems**
- The solution has a **natural recursive structure**
- You need to **traverse tree-like structures**
- The problem involves **backtracking or exploration**

### ✅ Key Properties

- **Base Case**: The simplest case that doesn't require recursion
- **Recursive Case**: The case where the function calls itself
- **Call Stack**: Tracks function calls and their states
- **Divide and Conquer**: Breaks problems into smaller parts
- **Stack Overflow Risk**: Can cause issues with deep recursion

---

### 💡 When to Use Recursion

| Scenario                                   | Use Recursion? | Reason                          |
|-------------------------------------------|-----------|----------------------------------|
| Tree/Graph traversal                      | ✅ Yes     | Natural recursive structure     |
| Divide and conquer problems               | ✅ Yes     | Break into smaller subproblems  |
| Backtracking algorithms                   | ✅ Yes     | Explore all possibilities       |
| Mathematical sequences                    | ✅ Yes     | Natural recursive definitions   |
| Simple iterative problems                 | ❌ No      | Use loops instead               |
| Problems with deep recursion              | ❌ No      | Risk of stack overflow          |

---

### 🔄 Recursion Process

#### 1. **Base Case Check**
- Check if we've reached the simplest case
- Return the result directly

#### 2. **Recursive Call**
- Break the problem into smaller subproblems
- Call the function recursively

#### 3. **Combine Results**
- Combine the results from recursive calls
- Return the final result

#### 4. **Unwinding**
- Return control back up the call stack
- Each level processes its part of the solution

---

### 🧪 Real-World Examples

| Use Case            | Description                                           |
|---------------------|-------------------------------------------------------|
| File System         | Directory traversal and file searching                |
| Mathematical Functions| Factorial, Fibonacci, power calculations             |
| Tree Operations     | Binary tree traversal, search, and manipulation      |
| Sorting Algorithms  | Merge sort, quick sort, heap sort                    |
| Game Logic          | Chess AI, puzzle solving, pathfinding                |
| Compiler Design     | Parsing expressions, syntax analysis                 |

---

### ⚠️ Best Practices

- **Always have a base case**: Prevent infinite recursion
- **Ensure progress**: Each recursive call should move toward the base case
- **Consider stack depth**: Be aware of potential stack overflow
- **Use tail recursion**: When possible, for optimization
- **Test edge cases**: Empty inputs, single elements, etc.
- **Consider iterative alternatives**: For performance-critical code

---

## 📚 Final Notes

Recursion is fundamental for solving problems with natural recursive structures. It's essential for:

- **Algorithm Design**: Many classic algorithms use recursion
- **Data Structure Operations**: Tree and graph algorithms
- **Problem Solving**: Breaking complex problems into manageable parts
- **Interview Preparation**: Frequently asked in technical interviews

**Key Takeaways:**
- Recursion breaks problems into smaller, similar subproblems
- Base cases are crucial to prevent infinite recursion
- The call stack manages recursive function calls
- Some problems are naturally recursive, others can be made recursive
- Consider iterative alternatives for performance-critical code

---

## 📝 LeetCode Problems (Recursion)

- [24. Swap Nodes in Pairs](./24.%20Swap%20Nodes%20in%20Pairs/)
- [25. Reverse Nodes in k-Group](./25.%20Reverse%20Nodes%20in%20k-Group/)
- [92. Reverse Linked List II](./92.%20Reverse%20Linked%20List%20II/)
- [206. Reverse Linked List](./206.%20Reverse%20Linked%20List/)
- [21. Merge Two Sorted Lists](./21.%20Merge%20Two%20Sorted%20Lists/)
- [23. Merge k Sorted Lists](./23.%20Merge%20k%20Sorted%20Lists/)
- [148. Sort List](./148.%20Sort%20List/)
- [2. Add Two Numbers](./2.%20Add%20Two%20Numbers/)
- [445. Add Two Numbers II](./445.%20Add%20Two%20Numbers%20II/)
