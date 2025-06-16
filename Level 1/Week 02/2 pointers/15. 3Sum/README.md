# 15. 3Sum

**Difficulty:** Medium  
**Link:** [LeetCode - 3Sum](https://leetcode.com/problems/3sum/)

---

## 🧠 Problem Statement

Given an integer array `nums`, return **all unique triplets** `[nums[i], nums[j], nums[k]]` such that:

- `i != j`, `i != k`, and `j != k`
- `nums[i] + nums[j] + nums[k] == 0`

The solution set must **not contain duplicate triplets**.

---

## 🧪 Examples

### Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Explanation:
- Triplet 1: (-1) + (-1) + 2 = 0
- Triplet 2: (-1) + 0 + 1 = 0

### Example 2:
Input: nums = [0,1,1]
Output: []

### Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]


---

## 🔍 Constraints

- `3 <= nums.length <= 3000`
- `-10⁵ <= nums[i] <= 10⁵`

---