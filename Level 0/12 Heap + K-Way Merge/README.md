## Section 1: Intuition & Real-Life Analogy

### 🔍 What is K-way Merge?
K-way merge means merging K sorted arrays/lists into one sorted array. It generalizes the 2-way merge used in merge sort.

### Real-Life Analogy: Grocery Checkout Lines
Imagine K checkout counters, each with customers already in arrival order. You want one global queue that preserves arrival order across all counters. A min-heap helps always pick the earliest among the K current fronts.

---

##  Section 2: Basic Implementation Using Min-Heap

###  Core Idea
Maintain a min-heap of the current head from each list. Pop the smallest, append to result, then push the next from that list.

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node { int value, listIndex, elementIndex; };
struct Cmp { bool operator()(const Node& a, const Node& b) const { return a.value > b.value; } };

vector<int> mergeK(const vector<vector<int>>& lists) {
    priority_queue<Node, vector<Node>, Cmp> pq;
    vector<int> ans;
    for (int i = 0; i < (int)lists.size(); ++i) if (!lists[i].empty()) pq.push({lists[i][0], i, 0});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        ans.push_back(cur.value);
        int j = cur.elementIndex + 1;
        if (j < (int)lists[cur.listIndex].size()) pq.push({lists[cur.listIndex][j], cur.listIndex, j});
    }
    return ans;
}
```

---

##  Section 3: Generalizing K-Way Merge

###  What Can We Merge?
- Sorted arrays
- Sorted linked lists
- Sorted file streams

---

##  Section 4: Common Interview Variants

1. Merge K Sorted Linked Lists (LeetCode #23)
2. External Sorting (merge sorted chunks from disk)
3. Streaming Merge (merge K logs/streams in real time)

###  Trade-offs

| Strategy | Time Complexity | Space Complexity | Use Case |
| --- | --- | --- | --- |
| Full sort each time | O(N log N) | O(N) | Static data |
| Heap-based merge | O(N log K) | O(K) | Streaming/partial merge |

###  Performance
- Time: O(N log K)
- Space: O(K)

---

##  Level 1: Foundation – Arrays & Heaps

| Problem | Platform | Focus |
| --- | --- | --- |
| Merge K Sorted Arrays | GeeksforGeeks | Classic K-way merge with arrays |
| Smallest Range Covering Elements from K Lists | LeetCode #632 | Min-heap + window tracking |
| Kth Smallest Element in a Sorted Matrix | LeetCode #378 | Min-heap with matrix coordinates |

---

##  Level 2: Linked Lists

| Problem | Platform | Focus |
| --- | --- | --- |
| Merge K Sorted Linked Lists | LeetCode #23 | Min-heap with ListNode* |
| Sort a Linked List | LeetCode #148 | Merge sort (2-way) |
| Merge Two Sorted Lists | LeetCode #21 | Base case for recursion/merge logic |

---

##  Level 3: Advanced

| Problem | Platform | Focus |
| --- | --- | --- |
| Kth Largest Element in a Stream | LeetCode #703 | Streaming + heap maintenance |
| Merge Intervals | LeetCode #56 | Interval merging |
| Top K Frequent Elements | LeetCode #347 | Frequency map + heap |

---

## Problems (direct links)

- https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
- https://leetcode.com/problems/merge-sorted-array/description/
- https://leetcode.com/problems/merge-k-sorted-lists/


