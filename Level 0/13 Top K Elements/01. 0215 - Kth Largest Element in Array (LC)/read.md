## Problem: Kth Largest Element in an Array

Given an integer array `nums` and an integer `k`, return the kth largest element in the array.

Input:
- First line: integer n (length of array) and k
- Second line: n integers (the array)

Output:
- The kth largest element in the array

Example:
Input
6 2
3 2 1 5 6 4

Output
5

Explanation:
- The sorted array is [1,2,3,4,5,6]
- The 2nd largest element is 5

Hint:
- Use a min-heap of size k to keep track of the k largest elements
- Or use quickselect algorithm for O(n) average time
