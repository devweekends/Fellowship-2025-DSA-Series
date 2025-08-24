# Merge Two Sorted Lists

**Difficulty:** Easy

## Problem Description

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one **sorted** list. The list should be made by splicing together the nodes of the first two lists.

Return *the head of the merged linked list*.

---

## Examples

### Example 1
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

### Example 2
Input: list1 = [], list2 = []
Output: []

### Example 3
Input: list1 = [], list2 = [0]
Output: [0]

---

## Constraints

- The number of nodes in both lists is in the range `[0, 50]`.
- `-100 <= Node.val <= 100`
- Both `list1` and `list2` are sorted in **non-decreasing** order.

---

## Approach

This problem can be solved elegantly using recursion:
1. Base case: if one list is empty, return the other list
2. Recursive case: compare the heads of both lists
3. Choose the smaller head and recursively merge the rest
4. Connect the chosen head with the result of recursive merge
5. Return the merged list

The recursive approach naturally handles the comparison and merging process.

---
