# Course Schedule

**Difficulty:** Medium

## Problem Description

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi` first if you want to take course `ai`.

- For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.

Return `true` if you can finish all courses. Otherwise, return `false`.

---

## Examples

### Example 1
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true

### Example 2
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false

---

## Constraints

- `1 <= numCourses <= 2000`
- `0 <= prerequisites.length <= 5000`
- `prerequisites[i].length == 2`
- `0 <= ai, bi < numCourses`
- All the pairs `prerequisites[i]` are **unique**.

---

## Approach

This problem can be solved using topological sort or cycle detection:
1. Build an adjacency list representation of the graph
2. Use DFS to detect cycles in the graph
3. If there's a cycle, it's impossible to complete all courses
4. Use a visited array to track visited nodes and detect cycles
5. Return true if no cycles are found

The key insight is that if there's a cycle in the dependency graph, it's impossible to complete all courses.

---
