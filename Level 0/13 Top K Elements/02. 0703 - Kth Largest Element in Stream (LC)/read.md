## Problem: Kth Largest Element in a Stream

Design a class to find the kth largest element in a stream. The class should have:
1. A constructor that takes k and an array of initial elements
2. A method `add(val)` that adds a new element and returns the kth largest

Input:
- First line: integer k and n (number of initial elements)
- Second line: n integers (initial elements)
- Next lines: integers to add one by one

Output:
- After each add operation, print the kth largest element

Example:
Input
3 2
4 5
8
2
3
5
10
9
4

Output
4
5
5
8
9

Explanation:
- Initial: [4,5], k=3 → 4 (3rd largest)
- Add 8: [4,5,8] → 5 (3rd largest)
- Add 2: [2,4,5,8] → 5 (3rd largest)
- Add 3: [2,3,4,5,8] → 5 (3rd largest)
- Add 5: [2,3,4,5,5,8] → 5 (3rd largest)
- Add 10: [2,3,4,5,5,8,10] → 8 (3rd largest)
- Add 9: [2,3,4,5,5,8,9,10] → 9 (3rd largest)
- Add 4: [2,3,4,4,5,5,8,9,10] → 9 (3rd largest)

Hint:
- Maintain a min-heap of size k
- When adding new element, if it's larger than heap.top(), replace it
