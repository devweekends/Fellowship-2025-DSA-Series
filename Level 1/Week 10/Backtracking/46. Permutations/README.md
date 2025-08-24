# Permutations

**Difficulty:** Medium

## Problem Description

Given an array `nums` of distinct integers, return *all the possible permutations*. You can return the answer in **any order**.

---

## Examples

### Example 1
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

### Example 2
Input: nums = [0,1]
Output: [[0,1],[1,0]]

### Example 3
Input: nums = [1]
Output: [[1]]

---

## Constraints

- `1 <= nums.length <= 6`
- `-10 <= nums[i] <= 10`
- All the integers of `nums` are **unique**.

---

## Approach

This problem uses backtracking to generate all possible permutations:
1. We build the permutation incrementally by choosing one element at a time
2. We use a boolean array to track which elements have been used
3. For each position, we try all unused elements
4. We backtrack by marking elements as unused and removing them from the current permutation
5. When we've used all elements, we add the complete permutation to our result

---
