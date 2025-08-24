# Merge k Sorted Lists

**Difficulty:** Hard

## Problem Description

You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

*Merge all the linked-lists into one sorted linked-list and return it.*

---

## Examples

### Example 1
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]

### Example 2
Input: lists = []
Output: []

### Example 3
Input: lists = [[]]
Output: []

---

## Constraints

- `k == lists.length`
- `0 <= k <= 10^4`
- `0 <= lists[i].length <= 500`
- `-10^4 <= lists[i][j] <= 10^4`
- `lists[i]` is sorted in **ascending order**.
- The sum of `lists[i].length` will not exceed `10^4`.

---

## Approach

This problem can be solved using divide and conquer with recursion:
1. Base case: if there are 0 or 1 lists, return the list or empty
2. Recursive case: divide the lists into two halves
3. Recursively merge each half
4. Merge the two merged halves using the two-list merge approach
5. Return the final merged list

The recursive approach naturally breaks down the problem into smaller subproblems.

---
