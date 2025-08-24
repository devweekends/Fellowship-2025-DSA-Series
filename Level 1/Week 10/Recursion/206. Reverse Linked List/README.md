# Reverse Linked List

**Difficulty:** Easy

## Problem Description

Given the `head` of a singly linked list, reverse the list, and return the reversed list.

---

## Examples

### Example 1
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

### Example 2
Input: head = [1,2]
Output: [2,1]

### Example 3
Input: head = []
Output: []

---

## Constraints

- The number of nodes in the list is the range `[0, 5000]`.
- `-5000 <= Node.val <= 5000`

---

## Approach

This is a classic recursion problem for reversing a linked list:
1. Base case: if head is null or only one node remains
2. Recursive case: reverse the rest of the list
3. Make the current node point to the reversed list
4. Return the new head (which is the last node of original list)

The recursive approach naturally handles the reversal by working backwards from the end of the list.

---
