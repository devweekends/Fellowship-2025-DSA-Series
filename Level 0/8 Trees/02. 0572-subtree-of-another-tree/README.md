# 572. Subtree of Another Tree

## Problem Description

Given the roots of two binary trees `root` and `subRoot`, return `true` if there is a subtree of `root` with the same structure and node values of `subRoot` and `false` otherwise.

A subtree of a binary tree `tree` is a tree that consists of a node in `tree` and all of this node's descendants. The tree `tree` could also be considered as a subtree of itself.

## Examples

### Example 1:
![Example 1](https://assets.leetcode.com/uploads/2021/04/28/subtree1-tree.jpg)

**Input:** `root = [3,4,5,1,2], subRoot = [4,1,2]`

**Output:** `true`

### Example 2:
![Example 2](https://assets.leetcode.com/uploads/2021/04/28/subtree2-tree.jpg)

**Input:** `root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]`

**Output:** `false`

## Constraints

- The number of nodes in the `root` tree is in the range `[1, 2000]`.
- The number of nodes in the `subRoot` tree is in the range `[1, 1000]`.
- `-10^4 <= root.val <= 10^4`
- `-10^4 <= subRoot.val <= 10^4`

## Related Topics

- Tree
- Depth-First Search
- String Matching
- Binary Tree
- Hash Function

## Difficulty

Easy
