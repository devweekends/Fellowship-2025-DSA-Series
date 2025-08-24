# Word Search

**Difficulty:** Medium

## Problem Description

Given an `m x n` grid of characters `board` and a string `word`, return `true` *if* `word` *exists in the grid*.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

---

## Examples

### Example 1
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

### Example 2
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

### Example 3
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

---

## Constraints

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 6`
- `1 <= word.length <= 15`
- `board` and `word` consists of only lowercase and uppercase English letters.

---

## Approach

This problem uses backtracking with DFS:
1. We start from each cell in the grid
2. For each cell, we try to match the first character of the word
3. If matched, we recursively search in all four directions (up, down, left, right)
4. We mark visited cells to avoid reusing them
5. We backtrack by unmarking cells when the current path doesn't lead to a solution
6. We return true if we can match the entire word

---
