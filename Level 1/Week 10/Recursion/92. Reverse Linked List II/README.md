# Reverse Linked List II

**Difficulty:** Medium

## Problem Description

Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes from position `left` to position `right`, and return the reversed list.

---

## Examples

### Example 1
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

### Example 2
Input: head = [5], left = 1, right = 1
Output: [5]

---

## Constraints

- The number of nodes in the list is `n`.
- `1 <= n <= 500`
- `-500 <= Node.val <= 500`
- `1 <= left <= right <= n`

---

## Approach

This problem can be solved using recursion:
1. Base case: if we reach the left position, start reversing
2. Recursive case: move forward until we reach the left position
3. Reverse the nodes from left to right
4. Connect the reversed portion with the rest of the list
5. Handle edge cases where left equals right

The key is to track the position and reverse only the specified range while maintaining the list structure.

---
