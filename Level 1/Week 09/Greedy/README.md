# 🎯 Data Structures Guide: Greedy Algorithms

This repository contains a comprehensive overview of **Greedy Algorithms** - fundamental algorithmic paradigms for making locally optimal choices to find globally optimal solutions.

---

## 📑 Table of Contents

- [🧠 General Understanding](#-general-understanding)
- [🌍 Real-Life Analogy](#-real-life-analogy)
- [📘 Greedy Algorithms](#-greedy-algorithms)
  - [✅ Key Properties](#key-properties)
  - [💡 When to Use Greedy](#-when-to-use-greedy)
  - [🧪 Real-World Examples](#-real-world-examples)
  - [⚠️ Best Practices](#-best-practices)
- [📚 Final Notes](#-final-notes)

---

## 🧠 General Understanding

### Greedy Algorithm

A **greedy algorithm** is an algorithmic paradigm that makes the locally optimal choice at each step with the hope of finding a globally optimal solution. The algorithm never reconsiders its choices.

---

## 🌍 Real-Life Analogy

Imagine a greedy algorithm as a **treasure hunter**:

- At each junction, choose the path that looks most promising immediately.
- Never go back to reconsider previous choices.
- Hope that local optimal choices lead to finding the most treasure overall.
- Sometimes this works perfectly (like following a clear treasure map), sometimes it doesn't (like getting stuck in local maxima).

---

## 📘 Greedy Algorithms

Greedy algorithms are great when:
- The problem has optimal substructure.
- Local optimal choices lead to global optimum.
- You need efficient solutions without exploring all possibilities.

### ✅ Key Properties

- **Makes locally optimal choices**
- **Never reconsiders previous decisions**
- **Often simple to implement**
- **Usually efficient in time complexity**
- **May not always give optimal solution**

---

### 💡 When to Use Greedy

| Scenario                                   | Use Greedy? | Reason                          |
|-------------------------------------------|-----------|----------------------------------|
| Activity Selection Problem                | ✅ Yes     | Optimal substructure exists     |
| Fractional Knapsack                      | ✅ Yes     | Can take fractions of items     |
| Huffman Coding                           | ✅ Yes     | Optimal prefix codes            |
| Minimum Spanning Tree                    | ✅ Yes     | Kruskal's/Prim's algorithms     |
| 0/1 Knapsack Problem                     | ❌ No      | Requires dynamic programming    |
| Traveling Salesman Problem              | ❌ No      | Needs exhaustive search         |

---

### 🧪 Real-World Examples

| Use Case            | Description                                           |
|---------------------|-------------------------------------------------------|
| Task Scheduling     | Choose tasks with earliest deadlines first           |
| Coin Change         | Use largest denomination coins first (specific cases)|
| Network Routing     | Choose shortest path at each hop                      |
| Resource Allocation | Allocate resources to highest priority requests      |
| Compression         | Build optimal encoding trees (Huffman)               |

---

### ⚠️ Best Practices

- **Verify greedy choice property** - local optimum leads to global optimum.
- **Prove correctness** - greedy doesn't always work.
- **Consider edge cases** - boundary conditions are crucial.
- **Think about sorting** - many greedy problems benefit from sorting first.
- **Use appropriate data structures** - heaps, priority queues often help.

---

## 📚 Final Notes

Greedy algorithms are powerful when they work, but require careful analysis to ensure correctness. They're essential for:

- **Algorithm Design**: Many classic algorithms use greedy approach
- **Optimization Problems**: When optimal substructure exists
- **Competitive Programming**: Fast solutions for specific problem types
- **Real-world Applications**: Scheduling, resource allocation, networking

**Key Takeaways:**
- Greedy algorithms make local optimal choices
- Not all problems can be solved optimally with greedy approach
- Always verify the greedy choice property
- Often combined with sorting for better results

---

## 📝 LeetCode Problems (Greedy)

- [53. Maximum Subarray](./53.%20Maximum%20Subarray/)
- [45. Jump Game II](./45.%20Jump%20Game%20II/)
- [134. Gas Station](./134.%20Gas%20Station/)
- [1899. Merge Triplets to Form Target Triplet](./1899.%20Merge%20Triplets%20to%20Form%20Target%20Triplet/)
- [678. Valid Parenthesis String](./678.%20Valid%20Parenthesis%20String/)
- [763. Partition Labels](./763.%20Partition%20Labels/)
