## Heaps for Beginners (Quick Intro)

### What is a Heap?
- A heap is a special tree-like structure where the top element is always the most important.
  - Min-heap: smallest number stays on top.
  - Max-heap: largest number stays on top.

### Real-life idea
- Hospital: most critical patient first → like picking the top from a heap.

### Why use a heap?
- You need quick access to the smallest/largest item while data keeps coming.

### Basic operations
- Peek (see top): O(1)
- Push (insert): O(log N)
- Pop (remove top): O(log N)

### How it’s stored
- Usually as an array. For index i: left = 2*i+1, right = 2*i+2.

### C++  
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    // Min-heap: smallest on top
    priority_queue<int, vector<int>, greater<int>> minH;
    minH.push(5); minH.push(2); minH.push(8);
    cout << minH.top() << "\n"; // 2

    // Max-heap: largest on top
    priority_queue<int> maxH;
    maxH.push(5); maxH.push(2); maxH.push(8);
    cout << maxH.top() << "\n"; // 8
}
```

### Common uses
- Top K elements, K-way merge, running median, Dijkstra’s shortest path.

###  Tips
- Use `greater<int>` to make a min-heap in C++.
- Don’t pop from an empty heap; check size first.


