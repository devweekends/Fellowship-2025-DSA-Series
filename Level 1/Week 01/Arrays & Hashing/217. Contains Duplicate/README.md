# 🧩 217. Contains Duplicate

**Difficulty:** Easy  
**Tags:** Array, Hash Table, Two Pointers, Sorting

---

## 📝 Problem Statement

Given an integer array `nums`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is **distinct**.

---

## 📥 Input

- A list of integers `nums`.

## 📤 Output

- A boolean value `true` if a duplicate exists, `false` otherwise.

---

## 🧪 Examples

### Example 1:
```txt
Input:  nums = [1, 2, 3, 1]
Output: true
Explanation: 1 is repeated.
```

### Example 2:

Input:  nums = [1, 2, 3, 4]
Output: false
Explanation: All elements are distinct.

### Example 3:

Input:  nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
Explanation: Multiple elements appear more than once.

## 📌 Constraints

- `1 <= nums.length <= 10⁵`
- `-10⁹ <= nums[i] <= 10⁹`

---