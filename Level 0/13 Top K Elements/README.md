## Part 1: Intuition & Real-Life Analogy

### Analogy
Instead of sorting everyone, you maintain a min-heap of size K:
- If a new score is higher than the smallest in the heap → replace it.
- At the end, the heap contains the top K scores.

### Why Heaps?
- Min-heap helps track **k largest** elements.
- Max-heap helps track **k smallest** elements.
- Efficient: O(log k) per insertion vs O(n log n) for sorting.

---
## Part 2: Heap Basics in C++

### Min-Heap & Max-Heap
```cpp
#include <queue>
using namespace std;

// Min-heap
priority_queue<int, vector<int>, greater<int>> minHeap;

// Max-heap
priority_queue<int> maxHeap;
```

### Operations
```cpp
minHeap.push(10);         // Insert
int top = minHeap.top();  // Access smallest
minHeap.pop();            // Remove smallest
```

---
## Part 3: Core Strategy

### For Top K Largest Elements
1. Use a **min-heap** of size K
2. For each element:
   - If heap size < K: push it
   - If heap size == K: if element > heap.top(), pop and push
3. Result: heap contains K largest elements

### For Top K Smallest Elements
1. Use a **max-heap** of size K
2. For each element:
   - If heap size < K: push it
   - If heap size == K: if element < heap.top(), pop and push
3. Result: heap contains K smallest elements

---
## Part 4: Problem Roadmap

### Level 1: Basic Top K
- Kth Largest Element in Array (LC 215)
- Kth Smallest Element in Array

### Level 2: Streaming Top K
- Kth Largest Element in Stream (LC 703)
- Top K Frequent Elements (LC 347)

### Level 3: Advanced Applications
- Top K Words by Frequency
- Top K Pairs with Smallest Sums
- Top K Closest Points to Origin

---
## Part 5: Time Complexity

| Operation | Time | Space |
|-----------|------|-------|
| Build heap of size K | O(K log K) | O(K) |
| Insert new element | O(log K) | O(1) |
| Get top K elements | O(1) | O(1) |
| Overall for N elements | O(N log K) | O(K) |
