# Subsets

**Difficulty:** Medium

## Problem Description

Given an integer array `nums` of **unique** elements, return *all possible subsets (the power set)*.

The solution set **must not** contain duplicate subsets. Return the solution in **any order**.

---

## Examples

### Example 1
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

### Example 2
Input: nums = [0]
Output: [[],[0]]

---

## Constraints

- `1 <= nums.length <= 10`
- `-10 <= nums[i] <= 10`
- All the numbers of `nums` are **unique**.

---

## Approach

This problem can be solved using backtracking where we:
1. For each element, we have two choices: include it or exclude it
2. We build the subset incrementally
3. When we reach the end of the array, we add the current subset to our result
4. We backtrack by removing the last added element to try the exclude option

---
