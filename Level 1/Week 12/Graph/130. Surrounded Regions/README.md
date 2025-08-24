# Surrounded Regions

**Difficulty:** Medium

## Problem Description

Given an `m x n` matrix `board` containing `'X'` and `'O'`, *capture all regions that are 4-directionally surrounded by* `'X'`.

A region is **captured** by flipping all `'O'`'s into `'X'`'s in that surrounded region.

---

## Examples

### Example 1
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

### Example 2
Input: board = [["X"]]
Output: [["X"]]

---

## Constraints

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 200`
- `board[i][j]` is `'X'` or `'O'`.

---

## Approach

This problem can be solved using DFS from the boundaries:
1. Start DFS from all 'O' cells on the boundaries
2. Mark all 'O' cells that are connected to boundaries as safe
3. Flip all remaining 'O' cells to 'X'
4. The key insight is to work backwards from the boundaries

The key insight is that only 'O' cells connected to boundaries cannot be surrounded, so we mark them as safe and flip the rest.

---
