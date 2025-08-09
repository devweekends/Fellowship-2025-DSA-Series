# Meeting Rooms III

**Difficulty:** Hard

## Problem Description

You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi, roomi] describes a meeting that starts at time starti and ends at time endi in room roomi.

All the meetings are non-overlapping.

Return the number of the room that held the most meetings. If there are multiple rooms, return the one with the smallest number.

---

## Examples

### Example 1
Input: n = 2, meetings = [[0,10,0],[5,15,1]]
Output: 0

### Example 2
Input: n = 3, meetings = [[0,10,0],[5,15,1],[10,20,2]]
Output: 0

---

## Constraints

- 1 <= n <= 100
- 1 <= meetings.length <= 10^4
- 0 <= starti < endi <= 10^9
- 0 <= roomi < n 