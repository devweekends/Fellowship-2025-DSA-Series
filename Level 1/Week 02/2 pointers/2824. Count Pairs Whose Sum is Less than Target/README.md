# 2824. Count Pairs Whose Sum is Less than Target

**Difficulty:** Easy  
**Link:** [LeetCode Problem](https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/)

---

## 🧠 Problem Statement

You are given:
- A 0-indexed integer array `nums` of length `n`
- An integer `target`

Your task is to count the number of **pairs** `(i, j)` such that:
- `0 <= i < j < n`
- `nums[i] + nums[j] < target`

Return the **count** of such pairs.

---

## 📌 Examples

### ✅ Example 1:
```txt
Input: nums = [-1, 1, 2, 3, 1], target = 2
Output: 3
Explanation:
The valid pairs are:

(0, 1): -1 + 1 = 0 < 2

(0, 2): -1 + 2 = 1 < 2

(0, 4): -1 + 1 = 0 < 2
 ```

### Example 2:
Input: nums = [-6, 2, 5, -2, -7, -1, 3], target = -2  
Output: 10
Explanation:
Valid pairs include:

(0,1), (0,3), (0,4), (0,5), (0,6)

(1,4)

(3,4), (3,5)

(4,5), (4,6)


### Constraints
1 <= nums.length <= 50

-50 <= nums[i], target <= 50