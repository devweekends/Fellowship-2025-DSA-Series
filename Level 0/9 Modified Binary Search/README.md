# Modified Binary Search

**Modified Binary Search** is where classic binary search evolves into solving complex **DSA problems** – from finding boundaries to solving optimization problems over search ranges.

If you’ve nailed basic binary search, this is your next step. Let's break it down.

## ❓ What is Binary Search?

Binary Search is a **searching algorithm** used on **sorted data**. It reduces the search space by half in each step.

> Keep halving until the solution is found.

### ❕ Intuition

1. You start with a **low** and **high** pointer.
2. Calculate the **mid** index.
3. Compare `arr[mid]` with the `target`.
4. Move left or right accordingly.

### Working Code (Classic Binary Search)

```cpp
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1; // Not found
}
```

---

## ❓ What is Modified Binary Search?

Modified Binary Search is an **extension** of standard binary search.

Instead of just finding an exact match, we use it to:

- ✅ Find boundaries (first, last index)
- ✅ Search over _answer space_ (time, pages, weights)
- ✅ Find min/max values under constraints
- ✅ Count or validate solutions using `isValid()` logic

> You’re searching over a **logical space** using binary decision making.

---

## ❓ How to Identify Modified Binary Search Problems

Before jumping into code, ask yourself:

- ✅ Is the input **sorted**, **monotonic**, or can it be treated as such?
- ✅ Can you define a **search space** (array, range of values, or answer space)?
- ✅ Can the problem be solved by **eliminating half of the search space** each step?
- ✅ Is there a **clear decision logic** (`isValid(mid)` or similar) that helps guide the search?
- ✅ Does the problem ask for:
  - **First** or **last** occurrence?
  - **Smallest** or **largest** value that satisfies a condition?
  - A **peak**, **minimum**, or **maximum**?
  - A solution with **O(log n)** time complexity?

If **yes**, it’s a good candidate for modified binary search.

---

## ❓ Why It Works

- Binary Search leverages **monotonic behavior** — either increasing or decreasing trends in data or decision space.
- Instead of checking every possibility (**brute force**), it eliminates **half of the search space** at every step using logic.
- In modified problems, we often don't compare elements directly.
- Instead, we ask **yes/no** questions like:

  ```cpp
  if (isValid(mid)) {
      // mid might be the answer or we try smaller
  } else {
      // mid is too small, try bigger
  }
  ```

---

## ❕ Modified Binary Search Templates

These patterns go beyond the basic binary search. They're essential when dealing with sorted arrays but with variations like duplicates, insertion points, peak detection, or binary searching over answers.

### 1. First Occurrence (Left Bound)

> Finds the first index where nums[i] == target

```cpp
int firstOccurrence(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result = mid;
            right = mid - 1;  // keep searching on the left
        }
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return result;  // returns -1 if not found
}
```

### 2. Last Occurrence (Right Bound)

> Finds the last index where nums[i] == target

```cpp
int lastOccurrence(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result = mid;
            left = mid + 1;  // keep searching on the right
        }
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return result;  // returns -1 if not found
}
```

### 3. Count of Occurrences

> Simply lastIndex - firstIndex + 1

```cpp
int countOccurrences(vector<int>& nums, int target) {
    int first = firstOccurrence(nums, target);
    if (first == -1) return 0;

    int last = lastOccurrence(nums, target);
    return last - first + 1;
}
```

### 4. Binary Search on Answer (Search Space Binary Search)

> When the answer is not a specific element, but a range of possible answers

```cpp
int binarySearchAnswer(int low, int high) {
    while (low < high) {
        int mid = low + (high - low) / 2;

        if (isValid(mid)) {
            high = mid;  // minimize or find lowest valid
        } else {
            low = mid + 1;
        }
    }
    return low;
}
```

**Used In:**

- Koko Eating Bananas
- Minimum Capacity to Ship Packages

### 5. Peak Element (Unimodal Binary Search)

> Finds an element such that nums[i] > nums[i - 1] && nums[i] > nums[i + 1]

```cpp
int findPeakElement(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[mid + 1]) {
            right = mid;  // peak is on the left (including mid)
        } else {
            left = mid + 1;  // peak is on the right
        }
    }

    return left;  // or right, both are same
}
```

### 6. Lower Bound

> Returns the first index where nums[i] >= target
> If target does not exist, it gives the insertion point

```cpp
int lowerBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }

    return left;
}
```

### 7. Upper Bound

> Returns the first index where nums[i] > target
> Also gives insertion point, but one step after duplicates

```cpp
int upperBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] <= target) left = mid + 1;
        else right = mid;
    }

    return left;
}
```

> This pattern works when we’re not searching in an array but over a logical range – using conditions.

---

## ❕ Some Classic Binary Search Problems

1. [Binary Search](https://leetcode.com/problems/binary-search)
2. [First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
3. [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)
4. [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)
5. [Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)
6. [Find Peak Element](https://leetcode.com/problems/find-peak-element/)
7. [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)
8. [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)

---

## ❕ Common Mistakes to Avoid

- ❌ Using `left < right` vs `left <= right` incorrectly
- ❌ Infinite loop due to `mid` not moving pointers
- ❌ Wrong mid calculation: `mid = (left + right) / 2` → overflow
  - ✅ Use: `mid = left + (right - left) / 2`
- ❌ Misunderstanding what to return (index vs value)
- ❌ Forgetting edge cases: empty array, single element, not found

---

## ⏱ Time and Space Complexity

| Variant                 | Time Complexity         | Space Complexity |
| ----------------------- | ----------------------- | ---------------- |
| Classic Binary Search   | O(log n)                | O(1)             |
| First/Last Occurrence   | O(log n)                | O(1)             |
| Binary Search on Answer | O(log(maxAnswer - min)) | O(1)             |
| Peak Finding            | O(log n)                | O(1)             |

---

## 🔆 Final Thoughts

Modified Binary Search is **where real interviews live**.

### Master this by:

- Practicing variations (bounds, peaks, isValid-style)
- Understanding search space (index vs value vs range)
- Visualizing how the pointers move
- Knowing which version of binary search to apply

> Always ask: **Am I searching elements or answers?**

Once you get that, everything else clicks.
