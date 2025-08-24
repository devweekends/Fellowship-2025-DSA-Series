# Letter Combinations of a Phone Number

**Difficulty:** Medium

## Problem Description

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in **any order**.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

```
2: abc
3: def
4: ghi
5: jkl
6: mno
7: pqrs
8: tuv
9: wxyz
```

---

## Examples

### Example 1
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

### Example 2
Input: digits = ""
Output: []

### Example 3
Input: digits = "2"
Output: ["a","b","c"]

---

## Constraints

- `0 <= digits.length <= 4`
- `digits[i]` is a digit in the range `['2', '9']`.

---

## Approach

This problem uses backtracking to generate all possible letter combinations:
1. We build the combination incrementally by choosing one letter at a time
2. For each digit, we try all possible letters that it can represent
3. We use a mapping array to convert digits to letters
4. We backtrack by removing the last added letter to try different combinations
5. When we've processed all digits, we add the complete combination to our result
6. We handle the empty string case separately

---
