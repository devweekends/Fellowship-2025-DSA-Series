# 🪟 Sliding Window Technique – Full Guide

## 🔍 General Understanding

The **Sliding Window** technique is a method for handling problems that involve **contiguous subarrays**, **substrings**, or **subsequences** by maintaining a subset (window) of elements and moving it across the structure efficiently.

Instead of using nested loops (`O(n²)`), sliding window allows you to process data in linear time (`O(n)`), reducing redundant calculations.

It applies mostly to problems involving:
- Arrays
- Lists
- Strings

---

## 📺 Real-Life Analogies

| Analogy | Explanation |
|--------|-------------|
| 🔭 Watching through a moving window | You shift your view one unit at a time without resetting your whole position. |
| 🧾 Credit card spending tracker | Keeping track of your spending in the past 30 days – as new transactions come in, old ones are dropped. |
| 📊 Moving averages in finance | Stock traders use a sliding time window to compute averages dynamically. |
| 🚘 Vehicle speed sensor | Measures average speed in the last 5 seconds of driving. |

---

## ❓ Why Use Sliding Window?

- **Efficiency:** Reduces time complexity from `O(n²)` to `O(n)` in many problems.
- **Minimizes Redundant Work:** Only update what's necessary when the window slides.
- **Simplifies Code:** Elegant alternatives to brute force with clear window bounds.

---

## 📌 When to Use Sliding Window?

Ask yourself:
- Does the problem involve **contiguous elements** (array, string)?
- Is the task to find **max, min, average, sum, count** in a range?
- Is there a **fixed window size** (`k`)?
- Does the size **change dynamically based on a condition**?

👉 If **yes**, then sliding window is likely the best approach.

---

## 🧪 Sliding Window Types

### 🧷 1. Fixed-Size Sliding Window

Used when the size of the window is constant (like `k`).

```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    // Add right element to window

    if (right - left + 1 == k) {
        // Process the current window
        // Remove left element to slide
        left++;
    }
}

```

## 🧷 2. Variable-Size Sliding Window

Used when the window size is **dynamic** and depends on a **condition**.

```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    // Expand window

    while (invalid_condition) {
        // Shrink window
        left++;
    }

    // Process the valid window
}
```

## 🛠️ Key Concepts & Code Patterns

### ✅ Expand Window

```cpp
window += arr[right];

```
## ✅ Shrink Window

```cpp
window -= arr[left];
left++;

```
## ✅ Calculate Window Size

To determine the current size of the sliding window:

```cpp
int windowSize = right - left + 1;
```

## 🧠 How to Approach a Sliding Window Problem

✅ **Check** if the problem involves **contiguous elements** (arrays, strings, etc.)

✅ **Decide the window type**:
- **Fixed Size**: A constant `k` is given.
- **Variable Size**: Adjust the size dynamically based on a condition.

✅ **Use two pointers**: `left` and `right` to manage the window boundaries.

✅ **Expand** the window using `right++` to include more elements.

✅ **Shrink** the window using `left++` when the condition is violated.

✅ **Process** the window by tracking metrics like:
- `min`, `max`, `average`, `count`, etc.

✅ **Handle edge cases**:
- Empty arrays
- `k > nums.size()`
- Negative numbers or potential overflows (use `long long` if needed)

---

## 📊 Time & Space Complexity

### ⏱ Time Complexity
- **O(n)** — Each element is added and removed from the window at most once.

### 🧠 Space Complexity
- **O(1)** — When using basic counters or fixed operations.
- **O(k)** or more — When using auxiliary data structures like:
  - `unordered_map` / `map` — For frequency counting.
  - `set` — For checking uniqueness or distinct values.
  - `deque` — For tracking max/min in a window.

