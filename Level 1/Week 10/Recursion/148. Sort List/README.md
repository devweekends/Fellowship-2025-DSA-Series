# Sort List

**Difficulty:** Medium

## Problem Description

Given the `head` of a linked list, return *the list after sorting it in **ascending order***.

---

## Examples

### Example 1
Input: head = [4,2,1,3]
Output: [1,2,3,4]

### Example 2
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

### Example 3
Input: head = []
Output: []

---

## Constraints

- The number of nodes in the list is in the range `[0, 5 * 10^4]`.
- `-10^5 <= Node.val <= 10^5`

---

## Approach

This problem can be solved using merge sort with recursion:
1. Base case: if head is null or only one node remains
2. Recursive case: find the middle of the list
3. Recursively sort the left and right halves
4. Merge the two sorted halves
5. Return the merged sorted list

The recursive approach naturally implements the divide and conquer strategy of merge sort.

---
