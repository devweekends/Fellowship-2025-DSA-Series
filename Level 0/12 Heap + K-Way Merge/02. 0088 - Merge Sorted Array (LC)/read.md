## Problem: Merge Sorted Array

You are given two sorted arrays:
- nums1 has length m + n. The first m elements are valid; the last n are empty slots (0 or any placeholder).
- nums2 has length n.
Merge nums2 into nums1 so that nums1 becomes a single sorted array of length m + n.

Input:
- First line: two integers m and n
- Second line: m integers (nums1's valid part)
- Third line: n integers (nums2)

Output:
- The merged sorted array of length m + n (contents of nums1), space-separated.

Hint: Fill from the end using two pointers i = m-1, j = n-1, k = m+n-1.


