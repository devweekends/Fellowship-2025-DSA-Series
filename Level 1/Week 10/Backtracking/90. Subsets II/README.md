# Subsets II

**Difficulty:** Medium

## Problem Description

Given an integer array `nums` that may contain **duplicates**, return *all possible subsets (the power set)*.

The solution set **must not** contain duplicate subsets. Return the solution in **any order**.

---

## Examples

### Example 1
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

### Example 2
Input: nums = [0]
Output: [[],[0]]

---

## Constraints

- `1 <= nums.length <= 10`
- `-10 <= nums[i] <= 10`

---

## Approach

This problem is similar to Subsets I but with duplicates in the input array:
1. We sort the array to group duplicates together
2. We use backtracking to generate all possible subsets
3. We skip duplicate elements at the same level to avoid duplicate subsets
4. We have two choices for each element: include it or exclude it
5. We handle duplicates carefully to ensure unique subsets

---
