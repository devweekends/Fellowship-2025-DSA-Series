# N-Queens

**Difficulty:** Hard

## Problem Description

The **n-queens puzzle** is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return *all distinct solutions to the **n-queens puzzle***. You may return the answer in **any order**.

Each solution contains a distinct board configuration of the n-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space, respectively.

---

## Examples

### Example 1
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.

### Example 2
Input: n = 1
Output: [["Q"]]

---

## Constraints

- `1 <= n <= 9`

---

## Approach

This is a classic backtracking problem:
1. We place queens one by one in each row
2. For each row, we try placing a queen in each column
3. Before placing a queen, we check if it's safe (no conflicts with existing queens)
4. We check for conflicts in the same column, same diagonal, and same anti-diagonal
5. If safe, we place the queen and recursively try to place queens in the next row
6. We backtrack by removing the queen to try different positions
7. When we've placed all n queens, we add the board configuration to our result

---
