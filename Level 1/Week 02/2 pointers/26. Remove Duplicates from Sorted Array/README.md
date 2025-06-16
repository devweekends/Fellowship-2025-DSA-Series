# 26. Remove Duplicates from Sorted Array

**Difficulty:** Easy  
**Link:** [LeetCode Problem](https://leetcode.com/problems/remove-duplicates-from-sorted-array)

---

## 🧠 Problem Statement

You are given a **sorted** array `nums` in **non-decreasing order**.  
Your task is to **remove duplicates in-place** so that each element appears **only once**, and return the new length `k` (i.e., number of unique elements).

The first `k` elements in `nums` should hold the unique elements in their original order.  
The elements beyond `k` can be anything — they are not checked.

---

## 📌 Examples

### ✅ Example 1:
```txt
Input: nums = [1, 1, 2]
Output: 2, nums = [1, 2, _]
Explanation: The function returns k = 2. The first two elements are the unique ones.
```

### ✅ Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Return k = 5. The first 5 elements of nums hold all the unique numbers.

### Constraints

1 <= nums.length <= 3 * 10^4

-100 <= nums[i] <= 100

The array nums is sorted in non-decreasing order.