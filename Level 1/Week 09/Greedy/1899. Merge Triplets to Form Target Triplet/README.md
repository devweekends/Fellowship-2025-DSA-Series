# Merge Triplets to Form Target Triplet

**Difficulty:** Medium

## Problem Description

A triplet is an array of three integers. You are given a 2D integer array `triplets`, where `triplets[i] = [ai, bi, ci]` describes the `ith` triplet. You are also given an integer array `target = [x, y, z]` that describes the **target** triplet.

To form the target triplet, you can apply the following operation as many times as you want (possibly zero):
- Choose two indices `i` and `j` (`0 <= i, j < triplets.length`) and **update** `triplets[i]` to become `[max(ai, aj), max(bi, bj), max(ci, cj)]`.

Return `true` if it is possible to form the **target** triplet `[x, y, z]` as an element of `triplets`, or `false` otherwise.

---

## Examples

### Example 1
Input: triplets = [[2,5,3],[1,8,4],[1,7,5]], target = [2,7,5]
Output: true
Explanation: Perform the operation on triplets[0] and triplets[2]:
triplets[0] = [max(2,1), max(5,7), max(3,5)] = [2,7,5].
The target triplet [2,7,5] is now an element of triplets.

### Example 2
Input: triplets = [[3,4,5],[4,5,6]], target = [3,2,5]
Output: false
Explanation: It is impossible to have [3,2,5] as an element because there is no 2 in the second position of any triplet.

### Example 3
Input: triplets = [[2,5,3],[2,3,4],[1,2,5],[5,2,3]], target = [5,5,5]
Output: true
Explanation: Perform the operation on triplets[0] and triplets[3]:
triplets[0] = [max(2,5), max(5,2), max(3,3)] = [5,5,3].
Perform the operation on triplets[0] and triplets[2]:
triplets[0] = [max(5,1), max(5,2), max(3,5)] = [5,5,5].
The target triplet [5,5,5] is now an element of triplets.

---

## Constraints

- `1 <= triplets.length <= 10^5`
- `triplets[i].length == target.length == 3`
- `1 <= ai, bi, ci, x, y, z <= 1000`

---
