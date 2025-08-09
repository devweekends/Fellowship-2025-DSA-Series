# Coin Change

**Difficulty:** Medium

## Problem Description

You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return `-1`.

You may assume that you have an infinite number of each kind of coin.

---

## Examples

### Example 1
Input: coins = [1,3,4], amount = 6
Output: 2
Explanation: 6 = 3 + 3

### Example 2
Input: coins = [2], amount = 3
Output: -1

### Example 3
Input: coins = [1], amount = 0
Output: 0

---

## Constraints

- `1 <= coins.length <= 12`
- `1 <= coins[i] <= 2^31 - 1`
- `0 <= amount <= 10^4`

---

## Approaches

This problem can be solved using 4 different dynamic programming approaches:

1. **Recursion** - Direct recursive implementation
2. **Memoization** - Top-down DP with caching
3. **Tabulation** - Bottom-up DP with array
4. **Space Optimization** - Optimized space complexity

---
