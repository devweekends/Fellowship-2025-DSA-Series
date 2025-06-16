# 680. Valid Palindrome II

**Difficulty:** Easy  
**Link:** [LeetCode Problem](https://leetcode.com/problems/valid-palindrome-ii)

---

## 🧠 Problem Statement

Given a string `s`, return `true` if the string can be a palindrome **after deleting at most one character** from it.

---

## 📌 Examples

### ✅ Example 1:
```txt
Input:  s = "aba"
Output: true
Explanation: Already a palindrome. No character needs to be removed.

```

### ✅ Example 2:

Input:  s = "abca"
Output: true
Explanation: Removing 'c' makes it "aba", which is a palindrome.

### ❌ Example 3:

Input:  s = "abc"
Output: false
Explanation: No way to make this a palindrome by removing just one character.


### Constraints

1 <= s.length <= 10^5

s consists of lowercase English letters only.