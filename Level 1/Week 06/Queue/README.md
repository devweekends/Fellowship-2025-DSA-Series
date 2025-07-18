# 🚀 Queue Data Structure - Complete Notes & Guide

## 📘 Definition

**Queue** is a linear data structure that works on the principle of **FIFO** (First In First Out).

---

## ✅ When to Use Queue

| Use Case                | Why Queue is Best                          |
|------------------------|--------------------------------------------|
| BFS (Breadth First Search) | Level-by-level traversal                   |
| Task scheduling        | Process tasks in order of arrival          |
| Print spooling         | Print jobs in FIFO order                   |
| CPU scheduling         | Round-robin scheduling                     |
| Sliding window         | Maintain window boundaries efficiently     |
| Monotonic operations   | Maintain increasing/decreasing sequences   |
| Simulation problems    | Real-world queue scenarios                 |

---

## 🔧 Queue Operations

| Operation | Syntax       | Description                 |
|----------|--------------|-----------------------------|
| Enqueue  | `q.push(x)`  | Add element to back         |
| Dequeue  | `q.pop()`    | Remove element from front   |
| Front    | `q.front()`  | View front element          |
| Back     | `q.back()`   | View back element           |
| Size     | `q.size()`   | Number of elements          |
| Empty    | `q.empty()`  | Check if queue is empty     |

---

## 🚀 Snippets

```cpp
queue<int> q;
q.push(x);
q.pop();
int front = q.front();
bool isEmpty = q.empty();
```

**Pattern: BFS with Queue**

```cpp
queue<Node*> q;
q.push(root);
while (!q.empty()) {
    Node* current = q.front();
    q.pop();
    // Process current node
    if (current->left) q.push(current->left);
    if (current->right) q.push(current->right);
}
```

---

## 🚀 Queue Implementation

### 1. Queue Using Arrays

```cpp
class Queue {
private:
    int* arr;
    int capacity;
    int front, rear, size;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
        this->size = 0;
    }

    void enqueue(int x) {
        if (isFull()) return;
        if (isEmpty()) front = 0;
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int result = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        return result;
    }

    int getFront() {
        return isEmpty() ? -1 : arr[front];
    }

    bool isEmpty() { return size == 0; }
    bool isFull() { return size == capacity; }
    int getSize() { return size; }

    ~Queue() { delete[] arr; }
};
```

### 2. Queue Using Linked List

```cpp
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front, *rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        Node* temp = front;
        int result = temp->data;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
        size--;
        return result;
    }

    int getFront() {
        return front ? front->data : -1;
    }

    bool isEmpty() { return front == nullptr; }
    int getSize() { return size; }

    ~Queue() {
        while (!isEmpty()) dequeue();
    }
};
```

---

## 🔄 Monotonic Queue Patterns

### Decreasing Queue (Max Queue)
```cpp
deque<int> dq;
for (int i = 0; i < n; i++) {
    // Remove smaller elements from back
    while (!dq.empty() && arr[dq.back()] <= arr[i]) {
        dq.pop_back();
    }
    dq.push_back(i);
    
    // Remove elements outside window from front
    while (!dq.empty() && dq.front() <= i - k) {
        dq.pop_front();
    }
    
    // dq.front() contains index of max in current window
}
```

### Increasing Queue (Min Queue)
```cpp
deque<int> dq;
for (int i = 0; i < n; i++) {
    // Remove larger elements from back
    while (!dq.empty() && arr[dq.back()] >= arr[i]) {
        dq.pop_back();
    }
    dq.push_back(i);
    
    // Remove elements outside window from front
    while (!dq.empty() && dq.front() <= i - k) {
        dq.pop_front();
    }
    
    // dq.front() contains index of min in current window
}
```

---

## 📊 Queue vs Stack Comparison

| Feature         | Queue (FIFO)     | Stack (LIFO)     |
|----------------|------------------|------------------|
| Order          | First In First Out| Last In First Out|
| BFS            | Perfect for      | Not suitable     |
| DFS            | Not suitable     | Perfect for      |
| Undo/Redo      | Not suitable     | Perfect for      |
| Task Scheduling| Perfect for      | Not suitable     |
| Expression Eval| Not suitable     | Perfect for      |

---

## 🎯 Advanced Queue Concepts

### 1. Circular Queue
- Efficient space utilization
- Fixed size with wraparound
- O(1) enqueue/dequeue operations

### 2. Priority Queue
- Elements with priority
- Highest priority served first
- Implemented using heap

### 3. Double-Ended Queue (Deque)
- Insert/delete from both ends
- More flexible than regular queue
- Can simulate both stack and queue

### 4. Monotonic Queue
- Maintains monotonic property
- Used for sliding window problems
- Efficient min/max queries

---

## 🔧 Template Code Patterns

### BFS Template
```cpp
queue<Node*> q;
q.push(start);
visited[start] = true;

while (!q.empty()) {
    Node* current = q.front();
    q.pop();
    
    // Process current node
    
    for (Node* neighbor : current->neighbors) {
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            q.push(neighbor);
        }
    }
}
```

### Sliding Window with Queue
```cpp
queue<int> q;
for (int i = 0; i < n; i++) {
    // Add current element
    q.push(i);
    
    // Remove elements outside window
    while (!q.empty() && q.front() <= i - k) {
        q.pop();
    }
    
    // Process window
    if (i >= k - 1) {
        // Window is complete
    }
}
```

---

## 🚀 Problem-Solving Strategies

### 1. Simulation Problems
- Use queue to simulate real-world scenarios
- Track state changes over time
- Handle complex rules and conditions

### 2. BFS Applications
- Level-order traversal
- Shortest path in unweighted graphs
- Connected components

### 3. Sliding Window
- Use monotonic queue for min/max
- Maintain window boundaries
- Optimize for O(n) solutions

### 4. Task Scheduling
- Process tasks in order
- Handle priorities and deadlines
- Resource allocation

---

## 📝 Common Mistakes to Avoid

1. **Forgetting to check empty queue** before accessing front/back
2. **Not handling circular queue wraparound** properly
3. **Using wrong data structure** (queue vs stack)
4. **Inefficient sliding window** implementation
5. **Not considering edge cases** in simulation problems

---

## 🎯 Practice Problems Summary

### Medium Problems (Challenging)
1. **1700. Number of Students Unable to Eat Lunch** - Queue simulation with complex logic
2. **2073. Time Needed to Buy Tickets** - Queue with time tracking
3. **649. Dota2 Senate** - Queue with voting rounds
4. **950. Reveal Cards In Increasing Order** - Queue with card ordering

### Hard Problems (Very Challenging)
1. **239. Sliding Window Maximum** - Monotonic queue
2. **862. Shortest Subarray with Sum at Least K** - Monotonic queue with prefix sum

Each problem demonstrates different aspects of queue usage and requires advanced problem-solving techniques.
