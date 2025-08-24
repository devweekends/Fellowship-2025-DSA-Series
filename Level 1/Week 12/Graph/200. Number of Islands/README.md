# Number of Islands

**Difficulty:** Medium

## Problem Description

Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return *the number of islands*.

An **island** is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

---

## Examples

### Example 1
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

### Example 2
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

---

## Constraints

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 300`
- `grid[i][j]` is `'0'` or `'1'`.

---

## Approach

This problem can be solved using DFS or BFS:
1. Iterate through each cell in the grid
2. When we find a land cell ('1'), start a DFS/BFS to explore the entire island
3. Mark visited cells to avoid counting them again
4. Count the number of times we start a new exploration (number of islands)

The key insight is to use a flood-fill approach to mark all connected land cells as visited.

---
