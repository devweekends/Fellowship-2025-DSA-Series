# Reverse Nodes in k-Group

**Difficulty:** Hard

## Problem Description

Given the `head` of a linked list, reverse the nodes of the list `k` at a time, and return the modified list.

`k` is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of `k` then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

---

## Examples

### Example 1
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

### Example 2
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

---

## Constraints

- The number of nodes in the list is `n`.
- `1 <= k <= n <= 5000`
- `0 <= Node.val <= 1000`

---

## Approach

This problem uses recursion with multiple steps:
1. Check if there are k nodes remaining to reverse
2. If yes, reverse the first k nodes
3. Recursively process the remaining nodes
4. Connect the reversed group with the result of recursive call
5. Handle the case where remaining nodes are less than k

The key is to reverse nodes in groups and maintain the connections between groups.

---
