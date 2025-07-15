## 📖 Understanding Fast and Slow Pointers

Fast and slow pointers are two references (or variables) that traverse a data structure at different speeds — typically used to:

- Detect cycles in linked lists or sequences
- Find the middle of a linked list
- Remove elements from the end with a gap
- Identify patterns where looping behavior exists

**How it works:**

- A **slow pointer** usually moves one step at a time.
- A **fast pointer** moves two steps at a time.
- If there's a cycle, the fast pointer will eventually meet the slow pointer inside the loop.
- In non-cyclic scenarios, this technique helps locate midpoints, detect ends, or optimize traversal.

> This technique is especially useful in space-efficient solutions because it uses constant memory and doesn't require modifying the data.

---

## 📘 Must Read

[Singly Linked List Tutorial – GeeksForGeeks](https://www.geeksforgeeks.org/dsa/singly-linked-list-tutorial/)  
This guide will help you refresh all basic operations and terminology used in linked lists.

---

## 📚 List of Problems

1. [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)  
2. [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)  
3. [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)  
4. [Happy Number](https://leetcode.com/problems/happy-number/)  
5. [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)  
6. [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

---

## Suggestions

- Make short notes of the key approach after solving each problem.  
- Avoid spending more than 30–40 minutes on a single problem.  
- If stuck, look up the problem on YouTube using its number for guided explanations.  
- Practice tracing pointer movements with diagrams to strengthen your understanding.  
- Revisit problems after a few days to check retention and reinforce the pattern.

---

Stay consistent and try to recognize where the fast and slow pointer logic naturally fits in. With enough practice, this will become an intuitive part of your problem-solving toolkit.
