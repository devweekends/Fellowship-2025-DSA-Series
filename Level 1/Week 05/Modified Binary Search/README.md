# Binary Search - Comprehensive Guide

---

### 🧠 Understanding:

Binary search is a powerful algorithm used to reduce the search space by half during each iteration.

> Cutting the problem into half again and again until it gets solved.

- Binary Search is a searching technique that **divides** the search space into two halves and eliminates half each time until the answer is found.
- Operates on sorted collections using **index positions**.

---

### 📌 Important Key Points:

- ✅ Only works on **sorted collections**
- ✅ Operates using **indices**, not elements directly
- ✅ Significantly improves search performance

---

## 🚀 Why Use Binary Search?

- **Efficiency**: Linear search takes O(n); Binary Search improves it to **O(log n)**
- **Sorted Data**: Can help find elements fast
- **Real-Life Examples**:
    - Monitoring recent network usage
    - Financial analysis (e.g., moving averages)
    - Searching long substrings

---

## ✅ When to Use Binary Search?

- Sorted Array or String (increasing/decreasing)
- Function is **monotonic**
- Can define search space clearly
- A “Yes/No” type decision can be made

---

## 🔍 Intuition

1. Start with entire array `[low...high]`
2. Pick middle: `mid = (low + high) / 2`
3. Check:
   - If `arr[mid] == target` → Found ✅
   - If `arr[mid] > target` → Search left half
   - If `arr[mid] < target` → Search right half

---

## 📘 Quick Example:

Searching 7 in `[1, 3, 5, 7, 9, 11]`

```cpp
low = 0, high = 5
mid = 2 → arr[2] = 5 → too small → low = 3

low = 3, high = 5
mid = 4 → arr[4] = 9 → too big → high = 3

low = 3, high = 3
mid = 3 → arr[3] = 7 → FOUND ✅
```

---

This section covers how to apply binary search to arrays sorted in descending order.
Since the array is sorted in reverse, we reverse the comparison logic to adapt binary search accordingly.

## 🔁 Binary Search on Descending Arrays

Just reverse the comparison:

```cpp
int binarySearchDescending(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}
```

---

## ♾️ Binary Search on Infinite Arrays

```cpp
// Step 1: Find boundaries
while (arr[high] < target) {
    low = high;
    high *= 2;
}

// Step 2: Apply binary search between low and high
```

```cpp
int searchInfiniteArray(ArrayReader& reader, int target) {
    int low = 0, high = 1;

    while (reader.get(high) < target) {
        low = high;
        high *= 2;
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int val = reader.get(mid);

        if (val == target) return mid;
        else if (val > target) high = mid - 1;
        else low = mid + 1;
    }

    return -1;
}
```

---

## 🔢 First and Last Occurrence (Sorted with Duplicates)

### First Occurrence

```cpp
int firstOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            result = mid;
            high = mid - 1;
        } else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return result;
}
```

### Last Occurrence

```cpp
if (arr[mid] == target) {
    result = mid;
    low = mid + 1;  // go right
}
```

### Count Occurrences

```cpp
int countOccurrences(vector<int>& arr, int target) {
    int first = firstOccurrence(arr, target);
    if (first == -1) return 0;

    int last = lastOccurrence(arr, target);
    return last - first + 1;
}
```

✅ **Key Takeaway**: Use `last - first + 1`

---

## 🔧 Templates

### Standard Binary Search

```cpp
while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) low = mid + 1;
    else high = mid - 1;
}
```

### Lower Bound

```cpp
while (low < high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < target) low = mid + 1;
    else high = mid;
}
return low;
```

### Upper Bound

```cpp
while (low < high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] <= target) low = mid + 1;
    else high = mid;
}
return low;
```

---

## 🔍 Binary Search on Answer

Used when solution lies in a range and can answer yes/no

```cpp
while (low <= high) {
    int mid = low + (high - low) / 2;
    if (isValid(mid)) {
        best = mid;
        high = mid - 1;
    } else {
        low = mid + 1;
    }
}
```

---

## 🧠 Matrix-Specific Binary Search

### Flattened Matrix Search

```cpp
int rows = matrix.size();
int cols = matrix[0].size();
int low = 0, high = rows * cols - 1;

while (low <= high) {
    int mid = low + (high - low) / 2;
    int mid_element = matrix[mid / cols][mid % cols];
    // standard binary search logic
}
```

### Without Flattening

```cpp
for (auto& row : matrix) {
    for (int num : row) {
        flat.push_back(num);
    }
}
```
## ⏱ Time and Space Complexity

| Operation                              | Time Complexity | Space Complexity |
|----------------------------------------|------------------|-------------------|
| Standard Binary Search                 | O(log n)         | O(1)              |
| First/Last Occurrence                  | O(log n)         | O(1)              |
| Infinite Array Search                  | O(log p), where p is the range | O(1) |
| Binary Search on 2D Matrix             | O(log(rows × cols)) | O(1)          |
| Binary Search on Answer (Optimization)| O(log(answer range)) | Depends on `isValid()` |

**How it's calculated:**
- Time complexity is derived from halving the search space each iteration.
- Space complexity is typically O(1) because only a few variables (low, high, mid) are used.
- For recursive binary search, space becomes O(log n) due to call stack.


## 📝 Final Tips

- If the entire matrix is sorted ➔ Flatten and apply binary search
- If only rows are sorted ➔ Do row-wise binary search
- If no sorting ➔ Binary search not applicable