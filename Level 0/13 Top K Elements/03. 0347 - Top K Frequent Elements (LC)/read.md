## Problem: Top K Frequent Elements

Given an integer array `nums` and an integer `k`, return the `k` most frequent elements.

Input:
- First line: integer n (length of array) and k
- Second line: n integers (the array)

Output:
- The k most frequent elements in any order

Example:
Input
6 2
1 1 1 2 2 3

Output
1 2

Explanation:
- Element 1 appears 3 times
- Element 2 appears 2 times  
- Element 3 appears 1 time
- The 2 most frequent elements are [1,2]

Note:
- It is guaranteed that the answer is unique
- The answer can be in any order

Hint:
- Use a hashmap to count frequencies
- Use a min-heap to keep top k frequent elements
- Or use bucket sort approach
