# Clone Graph

**Difficulty:** Medium

## Problem Description

Given a reference of a node in a **[connected](https://en.wikipedia.org/wiki/Connectivity_(graph_theory)#Connected_graph)** undirected graph.

Return a [**deep copy**](https://en.wikipedia.org/wiki/Object_copying#Deep_copy) (clone) of the graph.

Each node in the graph contains a val (`int`) and a list (`List[Node]`) of its neighbors.

---

## Examples

### Example 1
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]

### Example 2
Input: adjList = [[]]
Output: [[]]

### Example 3
Input: adjList = []
Output: []

---

## Constraints

- The number of nodes in the graph is in the range `[0, 100]`.
- `1 <= Node.val <= 100`
- `Node.val` is unique for each node.
- There are no repeated edges and no self-loops in the graph.
- The Graph is connected and all nodes can be visited starting from the given node.

---

## Approach

This problem requires a deep copy of a graph:
1. Use DFS or BFS to traverse the original graph
2. Create a new node for each node we visit
3. Use a hash map to track which nodes have been cloned
4. Copy the neighbors recursively
5. Handle the case where a node has already been cloned

The key insight is to use a hash map to avoid infinite recursion and ensure each node is cloned only once.

---
