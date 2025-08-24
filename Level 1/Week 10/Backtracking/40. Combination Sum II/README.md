# Combination Sum II

**Difficulty:** Medium

## Problem Description

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`.

Each number in `candidates` may only be used **once** in the combination.

**Note:** The solution set must not contain duplicate combinations.

---

## Examples

### Example 1
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: [[1,1,6],[1,2,5],[1,7],[2,6]]

### Example 2
Input: candidates = [2,5,2,1,2], target = 5
Output: [[1,2,2],[5]]

---

## Constraints

- `1 <= candidates.length <= 100`
- `1 <= candidates[i] <= 50`
- `1 <= target <= 30`

---

## Approach

This problem is similar to Combination Sum I but with key differences:
1. Each element can only be used once
2. We need to handle duplicates in the input array
3. We skip duplicate elements at the same level to avoid duplicate combinations
4. We use backtracking with careful duplicate handling

---
