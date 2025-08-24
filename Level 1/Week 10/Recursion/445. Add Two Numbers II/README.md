# Add Two Numbers II

**Difficulty:** Medium

## Problem Description

You are given two **non-empty** linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

---

## Examples

### Example 1
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

### Example 2
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

### Example 3
Input: l1 = [0], l2 = [0]
Output: [0]

---

## Constraints

- The number of nodes in each linked list is in the range `[1, 100]`.
- `0 <= Node.val <= 9`
- It is guaranteed that the list represents a number that does not have leading zeros.

---

## Approach

This problem is more complex than Add Two Numbers I because digits are in forward order:
1. First, we need to reverse both lists to work with least significant digits first
2. Use the recursive approach from Add Two Numbers I
3. Reverse the result back to get the correct order
4. Handle the carry propagation from least to most significant digits

The recursive approach handles the addition, while list reversal handles the digit order.

---
