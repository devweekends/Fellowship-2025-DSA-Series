# IPO

**Difficulty:** Hard

## Problem Description

Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. You are given n projects where the i-th project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start the corresponding project.

Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

Pick at most k distinct projects from given projects to maximize your final capital, and return the maximum capital you can obtain after finishing at most k distinct projects.

---

## Examples

### Example 1
Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4

### Example 2
Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
Output: 6

---

## Constraints

- 1 <= k <= 10^5
- 0 <= w <= 10^9
- n == profits.length == capital.length
- 1 <= n <= 10^5
- 0 <= profits[i], capital[i] <= 10^4 