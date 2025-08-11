# 40. Combination Sum II

## Problem Description

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`.

Each number in `candidates` may only be used **once** in the combination.

**Note:** The solution set must not contain duplicate combinations.

## Examples

### Example 1:

**Input:** `candidates = [10,1,2,7,6,1,5]`, `target = 8`

**Output:** `[[1,1,6],[1,2,5],[1,7],[2,6]]`

**Explanation:**
- 1 and 1 are candidates, and 1 + 1 + 6 = 8.
- 1 and 2 are candidates, and 1 + 2 + 5 = 8.
- 1 and 7 are candidates, and 1 + 7 = 8.
- 2 and 6 are candidates, and 2 + 6 = 8.

### Example 2:

**Input:** `candidates = [2,5,2,1,2]`, `target = 5`

**Output:** `[[1,2,2],[5]]`

## Constraints

- `1 <= candidates.length <= 100`
- `1 <= candidates[i] <= 50`
- `1 <= target <= 30`

## Related Topics

- Array
- Backtracking

## Difficulty

Medium