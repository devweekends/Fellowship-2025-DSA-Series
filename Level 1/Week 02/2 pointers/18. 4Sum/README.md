# 🧮 18. 4Sum

**Difficulty:** Medium  
**Link:** [LeetCode 18 - 4Sum](https://leetcode.com/problems/4sum)

---

## 🧠 Problem Statement

Given an array `nums` of `n` integers, return all **unique quadruplets** `[nums[a], nums[b], nums[c], nums[d]]` such that:

- `0 <= a, b, c, d < n`
- `a`, `b`, `c`, and `d` are **distinct**
- `nums[a] + nums[b] + nums[c] + nums[d] == target`

The answer can be returned in **any order**, but **must not contain duplicate quadruplets**.

---

## 📥 Example

### Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2], [-2,0,0,2], [-1,0,0,1]]

### Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]


---

## 📌 Constraints
- `1 <= nums.length <= 200