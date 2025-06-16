# 347. Top K Frequent Elements

**Difficulty:** Medium  
**Tag(s):** Hash Map, Heap, Sorting, Bucket Sort

---

## Problem Description

Given an integer array `nums` and an integer `k`, return the `k` most frequent elements.  
You may return the answer in **any order**.

---

## Examples

### Example 1
**Input:**
```text
nums = [1,1,1,2,2,3], k = 2
Output:
[1,2]
Explanation:

1 appears 3 times
2 appears 2 times
3 appears once
→ The top 2 frequent elements are [1,2]
```

### Example 2:
Input:

nums = [1], k = 1
Output:

[1]

### Constraints:
1 <= nums.length <= 10⁵

-10⁴ <= nums[i] <= 10⁴

k is in the range [1, the number of unique elements in the array]

It is guaranteed that the answer is unique

