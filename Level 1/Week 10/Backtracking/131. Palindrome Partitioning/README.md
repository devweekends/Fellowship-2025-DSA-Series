# Palindrome Partitioning

**Difficulty:** Medium

## Problem Description

Given a string `s`, partition `s` such that every substring of the partition is a **palindrome**. Return *all possible palindrome partitioning of* `s`.

---

## Examples

### Example 1
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

### Example 2
Input: s = "a"
Output: [["a"]]

---

## Constraints

- `1 <= s.length <= 16`
- `s` contains only lowercase English letters.

---

## Approach

This problem uses backtracking to find all valid palindrome partitions:
1. We try to partition the string at different positions
2. For each partition, we check if the substring is a palindrome
3. If it is a palindrome, we recursively partition the remaining string
4. We backtrack by removing the last partition to try different splits
5. When we've processed the entire string, we add the current partition to our result
6. We use a helper function to check if a string is a palindrome

---
