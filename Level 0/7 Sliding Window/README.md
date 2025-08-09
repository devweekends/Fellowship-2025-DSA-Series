# Sliding Window Pattern

The **Sliding Window** technique is a method for handling problems that involve **contiguous subarrays or substrings** by maintaining a subset (window) of elements and moving it across the structure efficiently.

Instead of using **nested loops (O(n²))**, sliding window allows you to process data in **linear time (O(n))**, reducing redundant calculations.

It applies mostly to problems involving:
- Arrays
- Lists
- Strings

### Real-Life Analogies:
- **Credit card spending tracker:** Keeping track of your spending in the past 30 days – as new transactions come in, old ones are dropped.
- **Vehicle speed sensor:** Measures average speed in the last 5 seconds of driving.

---

## ❓ When to Use Sliding Window

Ask yourself these questions:

- Is the input an **array** or a **string**?
- Are you dealing with a **subarray** or **substring**?
- Are you trying to compute:
  - ✅ Sum / Average
  - ✅ Minimum / Maximum
  - ✅ Length of longest or shortest window
  - ✅ Character frequency or uniqueness
- Does the window **move left to right**?
- Are you looking to **optimize brute force O(n²)**?

If yes, it’s probably a **Sliding Window** problem!

## ❓ Why It Works

- Reuses previously computed results to avoid redundant work
- Turns **O(n²)** brute-force into **O(n)**
- Uses **two pointers** to represent the window
- Dynamically adjusts window size to meet problem constraints

---

## ❓ What are the Types of Sliding Windows

### 1. Fixed Size Window
- Use when **Window size is known** (typically `k`)
- Move one step at a time
- ✅ Use case: max sum of subarray of size `k`

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

### 2. Variable Size Window
- Use when **Window size is not known** initially
- Dynamically expand/shrink based on condition
- ✅ Use case: longest substring without repeating characters

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

---

## ❓ How to Approach a Sliding Window Problem

✅ Check if the problem involves **contiguous elements** (arrays, strings, etc.)

✅ Decide the **window type**:
- **Fixed Size:** A constant `k` is given.
- **Variable Size:** Adjust the size dynamically based on a condition.

✅ Use **two pointers:** `left` and `right` to manage the window boundaries.

✅ Expand the window using `right++` to include more elements.

✅ Shrink the window using `left++` when the condition is violated.

✅ Process the window by tracking metrics like:
- min, max, average, count, etc.

✅ Handle edge cases:
- Empty arrays
- `k > nums.size()`
- Negative numbers or potential overflows (use `long long` if needed)

---

## ❕ Some Classic Sliding Window Problems

### 🔒 Fixed Size

1. [Substrings of Size Three with Distinct Characters](https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/)
2. [Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/)
3. [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/)
4. [Maximum Number of Vowels in a Substring of Given Length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)
5. [Check If a String Contains All Binary Codes of Size K](https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/)
6. [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)
7. [Permutation in String](https://leetcode.com/problems/permutation-in-string/)

### 🔓 Dynamic Size

8. [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
9. [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)
10. [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)
11. [Subarrays product with Sum Less Than K](https://leetcode.com/problems/subarray-product-less-than-k/)

---

## ❕ Common Patterns to Remember

✅ **Expand Window**
```cpp
window += arr[right];
```
✅ **Shrink Window**
```cpp
window -= arr[left];
left++;
```
✅ **Calculate Window Size**
```cpp
int windowSize = right - left + 1;
```

---

## ❌ Common Mistakes to Avoid

- Forgetting to **shrink the window** when needed
- Incorrect **window size calculations**: `right - left + 1` vs `right - left`
- Mishandling **frequency maps** while shrinking
- **Off-by-one errors** in loops
- Using unnecessary **nested loops**
- Ignoring **edge cases** like string length < `k`

---

## ❕ Time & Space Complexity

### ⏱ Time Complexity
- **O(n)** — Each element is added and removed from the window at most once.

### 🧳 Space Complexity
- **O(1)** — When using basic counters or fixed operations.
- **O(k) or more** — When using auxiliary data structures like:
  - `unordered_map` / `map` — For frequency counting.
  - `set` — For checking uniqueness or distinct values.
  - `deque` — For tracking max/min in a window.

---

## 🆚 Tip: Sliding Window vs Two Pointers

| Use Case | Go For             |
|----------|--------------------|
| Need to process contiguous subarrays/substrings?         | Sliding Window     |
| Working with sorted/unsorted arrays and need to move both ends independently (not necessarily contiguous)? | Two Pointers       |
| Need to expand and shrink based on a condition (like sum, distinct chars, etc.)? | Dynamic Sliding Window |

---

## 🔆 Final Thoughts

Sliding Window is one of the most **interview-worthy** patterns you must master. Practice recognizing its pattern, applying the right structure, and managing edge cases.

When you understand **why and when** to grow/shrink your window — you'll turn brute force into beautiful linear-time solutions.