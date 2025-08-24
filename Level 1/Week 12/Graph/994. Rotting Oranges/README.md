# Rotting Oranges

**Difficulty:** Medium

## Problem Description

You are given an `m x n` `grid` where each cell can have one of three values:

- `0` representing an empty cell,
- `1` representing a fresh orange, or
- `2` representing a rotten orange.

Every minute, any fresh orange that is **4-directionally adjacent** to a rotten orange becomes rotten.

Return *the minimum number of minutes that must elapse until no cell has a fresh orange*. If *this is impossible, return* `-1`.

---

## Examples

### Example 1
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

### Example 2
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1

### Example 3
Input: grid = [[0,2]]
Output: 0

---

## Constraints

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 10`
- `grid[i][j]` is only `0`, `1`, or `2`.

---

## Approach

This problem can be solved using BFS:
1. Find all rotten oranges and add them to a queue
2. Use BFS to simulate the rotting process minute by minute
3. Track the number of minutes elapsed
4. Check if all fresh oranges become rotten
5. Return -1 if some fresh oranges remain unreachable

The key insight is to use BFS to simulate the spreading process level by level, where each level represents one minute.

---
