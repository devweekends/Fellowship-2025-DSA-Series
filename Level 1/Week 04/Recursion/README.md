# 📘 Recursion & Backtracking – A Beginner’s Guide

This repository contains solutions for simple recursion problems involving printing natural numbers in increasing and decreasing order.

## 🔁 Recursion

### Understanding

**Recursion is a thought process** — it involves a function calling itself until a specified condition is met.

To use recursion effectively, always know:
- What the **input** is.
- What the **output** should be.

### 🧩 Parts of a Recursive Function

- **Base Case**  
  The stopping condition to prevent infinite recursion.  
  → *Tip: Try solving the problem for the smallest input to discover the base case.*

- **Recursive Case**  
  Describes how the problem is broken into smaller pieces and solved recursively.

---

### 📚 Recursion Stack

When functions call themselves recursively, each call is stored in a **Recursion Stack**. Once the base case is hit, calls are resolved one by one as they return.

#### ⚠️ Stack Overflow
If the base case is missing or unreachable, recursive calls never stop, causing a **stack overflow**.

---

### 🧠 Types of Recursion

There are two main styles:

#### Parameterized Recursion
- Parameters are changed in every recursive call.
- Useful for tracking progress (e.g., accumulating results).

#### Functional Recursion
- Function returns results without modifying parameters.
- Great for divide-and-conquer problems.

| Aspect | Parameterized Recursion | Functional Recursion |
|--------|--------------------------|-----------------------|
| **State** | Passed and updated at each call | No state change, just return values |
| **Memory Usage** | Can use more memory | More memory efficient |
| **Result** | Accumulates result via parameters | Builds result via return values |
| **Use Cases** | Summations, path tracking | Tree traversal, Fibonacci |
| **Complexity** | Slightly complex but stateful | Easier to conceptualize |

---

## 🧮 Example: Factorial

### Code

```cpp
int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

```
### Call Breakdown
```cpp
factorial(4)
   ↓
4 * factorial(3)
       ↓
   3 * factorial(2)
          ↓
     2 * factorial(1)
             ↓
           1 (Base Case)
```
### Execution Stack (Bottom to Top Resolution)
 ```cpp
factorial(1) → 1
factorial(2) → 2 * 1 = 2
factorial(3) → 3 * 2 = 6
factorial(4) → 4 * 6 = 24
```

### 🧮 Time & Space Complexity

🕒 Time Complexity
Recursive functions can be analyzed using:

Recurrence Relations
Counting Recursive Calls

### Example
```cpp
int fact(int n){
    if (n == 0) return 1;
    return n * fact(n - 1);
}
```
Recursive Calls: n

Work per Call: O(1)

Total Time Complexity: O(n)

### 🧠 Space Complexity
Every recursive call uses stack memory, regardless of additional variables.

Number of Stack Frames: n

Total Space Complexity: O(n)

This happens because each function call waits for the next to complete, building up memory usage in the call stack.

### 🔄 Recursion Styles
There are two primary styles for writing recursive functions:

1. 📥 Parameterized Recursion
State is passed and modified through parameters.

Useful when tracking cumulative results (like sums, indices, etc.).

```cpp
void func(int i, int sum) {
    if (i < 1) {
        cout << sum;
        return;
    }
    func(i - 1, sum + i);
}
```

### 2. 📤 Functional Recursion
The function returns values and combines results.

Ideal for divide-and-conquer problems (e.g., tree traversal, Fibonacci, mergesort).

```cpp
int sum(int n) {
    if (n == 0) return 0;
    return n + sum(n - 1);
}
```
## 📊 Parameterized vs Functional Recursion

| **Aspect**         | **Parameterized Recursion**                         | **Functional Recursion**                      |
|--------------------|-----------------------------------------------------|-----------------------------------------------|
| **State Handling** | State passed and updated at each call               | No state change; relies on return values      |
| **Memory**         | May use more memory due to extra state tracking     | Often more memory efficient                   |
| **Use Case**       | Cumulative operations (e.g., running sum, prefix)   | Divide-and-conquer (e.g., recursion trees)    |

---

## 🧵 Common Pitfall: Stack Overflow

One of the most common recursion mistakes is **missing the base case**, which results in infinite recursion and eventually a **stack overflow**.

### ❌ Bad Example:
```cpp
int f(int n) {
    return f(n - 1); // 🚨 No base case!
}
```

### 💥 What happens?
Recursive calls continue forever.

The stack keeps growing.

Eventually, the program crashes due to a stack overflow.

✅ Always include a base case to stop recursion!


## 🛠️ How to Run

Make sure to have a suitable environment for your implementation language (Python, C++, etc.).

```bash
# Example (Python)
python fibonacci.py

# Example (C++)
g++ factorial.cpp -o factorial && ./factorial
```







