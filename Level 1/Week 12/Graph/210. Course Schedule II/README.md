# Course Schedule II

**Difficulty:** Medium

## Problem Description

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi` first if you want to take course `ai`.

- For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.

Return *the ordering of courses you should take to finish all courses*. If there are many valid answers, return **any** of them. If it is impossible to finish all courses, return **an empty array**.

---

## Examples

### Example 1
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3]

### Example 2
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: []

---

## Constraints

- `1 <= numCourses <= 2000`
- `0 <= prerequisites.length <= 5000`
- `prerequisites[i].length == 2`
- `0 <= ai, bi < numCourses`
- `ai != bi`
- All the pairs `prerequisites[i]` are **unique**.

---

## Approach

This problem requires finding a topological order:
1. Build an adjacency list representation of the graph
2. Use DFS to detect cycles and build topological order
3. If there's a cycle, return empty array
4. Use a visited array to track visited nodes and detect cycles
5. Build the result in reverse topological order

The key insight is to use DFS with post-order traversal to build the topological order.

---
