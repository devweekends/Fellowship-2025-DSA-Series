## Problem: Merge K Sorted Arrays

You are given K sorted arrays. Merge them into a single sorted array.

Input:
- First line: integer K (number of arrays)
- For each i from 1..K:
  - First an integer n (size of array i)
  - Then n integers in non-decreasing order

Output:
- All elements of the K arrays merged into one sorted array, space-separated.

Hint:
- Keep a min-heap of the current first unused element from each array.
- Each time, remove the smallest and insert the next element from the same array.


