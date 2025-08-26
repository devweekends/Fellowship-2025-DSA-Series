## Problem: Merge K Sorted Linked Lists

You are given k linked lists, each sorted in non-decreasing order. Merge all the
linked lists into one sorted linked list and return the head of the merged list.

Input:
- First line: integer k (number of lists)
- For each i from 1..k:
  - First an integer n (length of list i)
  - Then n integers in non-decreasing order

Output:
- The merged linked list values in non-decreasing order, space-separated.

Hint:
- Use a min-heap of ListNode* by value. Pop the smallest, append to answer, and push its next.


