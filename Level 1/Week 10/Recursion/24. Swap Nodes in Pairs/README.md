# Swap Nodes in Pairs

**Difficulty:** Medium

## Problem Description

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem **without modifying the values** in the list's nodes (i.e., only nodes themselves may be changed.)

---

## Examples

### Example 1
Input: head = [1,2,3,4]
Output: [2,1,4,3]

### Example 2
Input: head = []
Output: []

### Example 3
Input: head = [1]
Output: [1]

---

## Constraints

- The number of nodes in the list is in the range `[0, 100]`.
- `0 <= Node.val <= 100`

---

## Approach

This problem can be solved using recursion:
1. Base case: if head is null or only one node remains
2. Recursive case: swap the first two nodes
3. Recursively swap the remaining nodes
4. Return the new head of the swapped pair

The key insight is to handle the swapping at each level and then recursively process the rest of the list.

---
