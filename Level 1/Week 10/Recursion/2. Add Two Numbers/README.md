# Add Two Numbers

**Difficulty:** Medium

## Problem Description

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

---

## Examples

### Example 1
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

### Example 2
Input: l1 = [0], l2 = [0]
Output: [0]

### Example 3
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

---

## Constraints

- The number of nodes in each linked list is in the range `[1, 100]`.
- `0 <= Node.val <= 9`
- It is guaranteed that the list represents a number that does not have leading zeros.

---

## Approach

This problem can be solved using recursion:
1. Base case: if both lists are null and no carry remains
2. Recursive case: add current digits and carry
3. Create a new node with the sum modulo 10
4. Recursively add the remaining digits with the carry
5. Connect the current node with the recursive result

The recursive approach naturally handles the digit-by-digit addition and carry propagation.

---
