# 🗂️ Data Structures Guide: Heaps (Priority Queues)

This repository contains a comprehensive overview of **Heaps** and **Priority Queues** - essential data structures for efficient element management based on priority.

---

## 📑 Table of Contents

- [🧠 General Understanding](#-general-understanding)
- [🌍 Real-Life Analogy](#-real-life-analogy)
- [📘 Heaps](#-heaps)
  - [✅ Key Properties](#key-properties)
  - [💡 When to Use Heaps](#-when-to-use-heaps)
  - [🧪 Real-World Examples](#-real-world-examples)
  - [🔢 Heap Syntax (C++)](#-heap-syntax-c)
  - [⚠️ Best Practices](#-best-practices)
- [🔐 Priority Queues](#-priority-queues)
  - [⚙️ How Priority Queues Work](#️-how-priority-queues-work)
  - [💼 Applications](#-applications)
  - [🗃️ Heap Types](#️-heap-types)
    - [✅ Max Heap](#max-heap)
    - [🔢 Min Heap](#min-heap)
    - [🆚 Comparison](#comparison)
  - [📌 Use Cases](#-use-cases)
  - [⚠️ Best Practices](#️-best-practices-1)
- [📚 Final Notes](#-final-notes)

---

## 🧠 General Understanding

### Heap

A **heap** is a specialized tree-based data structure that satisfies the **heap property**. It's commonly implemented as a **binary heap**, which is a complete binary tree where each parent node is either greater than or equal to (max heap) or less than or equal to (min heap) its children.

---

## 🌍 Real-Life Analogy

Imagine a heap as a **hospital emergency room**:

- Patients are prioritized by severity (priority).
- The most critical patient (highest priority) is treated first.
- New patients can arrive and be inserted into the queue.
- After treating a patient, the next most critical one is selected.

---

## 📘 Heaps

Heaps are great when:
- You need to efficiently find the maximum/minimum element.
- You need to maintain a dynamic collection with priority-based access.
- You want to implement efficient sorting algorithms.

### ✅ Key Properties

- **Complete binary tree structure**
- **Heap property** (max or min)
- **O(log n)** insertion and deletion
- **O(1)** access to root (max/min element)
- **O(n)** space complexity

---

### 💡 When to Use Heaps

| Scenario                                   | Use Heap? | Reason                          |
|-------------------------------------------|-----------|----------------------------------|
| Find max/min element efficiently          | ✅ Yes     | O(1) access to root             |
| Priority-based scheduling                 | ✅ Yes     | Natural priority queue          |
| K-th largest/smallest element             | ✅ Yes     | Efficient with min/max heap     |
| Frequent insertions and deletions         | ✅ Yes     | O(log n) operations             |
| Need sorted order                         | ❌ No      | Use sorting algorithms          |
| Random access to elements                 | ❌ No      | Use arrays or hash maps         |

---

### 🧪 Real-World Examples

| Use Case            | Description                                           |
|---------------------|-------------------------------------------------------|
| Task Scheduler      | Prioritize tasks by importance/urgency                |
| Hospital ER         | Treat patients by severity level                      |
| Network Routing     | Route packets by priority/bandwidth                   |
| Job Queue           | Process jobs by priority or deadline                  |
| Event System        | Handle events in chronological order                  |

---

### 🔢 Heap Syntax (C++)

```cpp
#include <queue>
#include <vector>

// Max Heap (default)
priority_queue<int> maxHeap;

// Min Heap
priority_queue<int, vector<int>, greater<int>> minHeap;

// Custom comparator
struct Compare {
    bool operator()(int a, int b) {
        return a > b; // Min heap
    }
};
priority_queue<int, vector<int>, Compare> customHeap;

// Operations
maxHeap.push(10);           // Insert
int top = maxHeap.top();    // Get max element
maxHeap.pop();              // Remove max element
bool empty = maxHeap.empty(); // Check if empty
int size = maxHeap.size();  // Get size
```

### ⚠️ Best Practices

- Use `priority_queue` from STL for most cases.
- Choose max heap for finding largest elements.
- Choose min heap for finding smallest elements.
- Consider using custom comparators for complex objects.
- Remember that heap operations are O(log n).
- Use heaps for top-k problems efficiently.

---

## 🔐 Priority Queues

A **priority queue** is an abstract data type that operates like a regular queue but with a priority attached to each element. Elements with higher priority are served before elements with lower priority.

---

### ⚙️ How Priority Queues Work

1. **Insertion**: New elements are added to the queue.
2. **Priority Maintenance**: The queue maintains the heap property.
3. **Extraction**: The highest/lowest priority element is removed.
4. **Reorganization**: The heap is restructured to maintain properties.

```text
Insert -> Maintain Heap Property -> Extract Max/Min -> Reorganize
```

### 💼 Applications

- **Task Scheduling**: Operating system process scheduling
- **Event-driven Simulation**: Discrete event simulation
- **Graph Algorithms**: Dijkstra's, Prim's, Kruskal's
- **Data Compression**: Huffman coding
- **Sorting**: Heap sort algorithm

---

### 🗃️ Heap Types

#### ✅ Max Heap

- **Root**: Contains the maximum element
- **Property**: Parent ≥ Children
- **Use Case**: Find k-th largest element

#### 🔢 Min Heap

- **Root**: Contains the minimum element
- **Property**: Parent ≤ Children
- **Use Case**: Find k-th smallest element

---

### 🆚 Comparison

| Feature           | Max Heap | Min Heap         |
|------------------|----------|-------------------|
| Root Element     | Maximum  | Minimum           |
| K-th Largest     | ✅ Yes    | ❌ No             |
| K-th Smallest    | ❌ No     | ✅ Yes            |
| Default in C++   | ✅ Yes    | ❌ No             |
| Implementation   | `priority_queue<int>` | `priority_queue<int, vector<int>, greater<int>>` |

---

### 📌 Use Cases

| Scenario                        | Use Priority Queue? | Reason                             |
|----------------------------------|---------------------|------------------------------------|
| Find top-k elements              | ✅ Yes               | Efficient O(k log n) solution      |
| Task scheduling by priority      | ✅ Yes               | Natural priority-based ordering    |
| Merge k sorted lists             | ✅ Yes               | Efficient k-way merge              |
| Real-time event processing       | ✅ Yes               | Process by timestamp/priority      |
| Network packet routing           | ✅ Yes               | Route by priority/bandwidth        |

---

### ⚠️ Best Practices (Priority Queues)

- **Choose the right heap type** for your use case.
- **Use custom comparators** for complex objects.
- **Consider time complexity** - heap operations are O(log n).
- **Monitor memory usage** - heaps can be memory-intensive.
- **Use for top-k problems** - more efficient than sorting.

---

## 📚 Final Notes

Heaps and priority queues are fundamental data structures that provide efficient solutions for priority-based problems. They're essential for:

- **Algorithm Design**: Many algorithms rely on heaps
- **System Design**: Task scheduling, event processing
- **Competitive Programming**: Top-k problems, greedy algorithms
- **Real-world Applications**: Operating systems, networking

**Key Takeaways:**
- Heaps provide O(log n) insertion/deletion and O(1) access to extremal elements
- Choose max heap for largest elements, min heap for smallest
- Priority queues are the natural choice for priority-based problems
- Use STL's `priority_queue` for most implementations

---

## 📝 LeetCode Problems (Heaps)

- [253. Meeting Rooms II](./253. Meeting Rooms II/)
- [703. Kth Largest Element in a Stream](./703. Kth Largest Element in a Stream/)
- [1046. Last Stone Weight](./1046. Last Stone Weight/)
- [414. Third Maximum Number](./414. Third Maximum Number/)
- [Meeting Rooms III](./Meeting Rooms III/)
- [IPO](./IPO/)
- [Find Median from Data Stream](./Find Median from Data Stream/)
