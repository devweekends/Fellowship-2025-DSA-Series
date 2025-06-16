# 49. Group Anagrams

**Difficulty:** Medium

---

## Problem Description

Given an array of strings `strs`, group the anagrams together. You can return the answer in **any order**.

Two strings are **anagrams** if they contain the same characters with the same frequency, but possibly in a different order.

---

## Examples

### Example 1

**Input:**
```txt
strs = ["eat","tea","tan","ate","nat","bat"]


[["bat"],["nat","tan"],["ate","eat","tea"]]

```
### Explanation:

"eat", "tea", and "ate" are anagrams.
"tan" and "nat" are anagrams.
"bat" has no anagram pair.

### Example 2

**Input:**
```txt
strs = [""]


[[""]]
```
### Explanation:

"eat", "tea", and "ate" are anagrams.
"tan" and "nat" are anagrams.
"bat" has no anagram pair.
