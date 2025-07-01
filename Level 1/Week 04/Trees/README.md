# 🌳 Tree Data Structures: A Comprehensive Guide

## 📘 What is a Tree?

A **Tree** is a hierarchical, non-linear data structure that consists of nodes connected by edges. Unlike arrays, stacks, and queues, which are linear, trees represent data in a branching structure.

Every tree has:

- A **Root** node (starting point)
- **Children** nodes (descendants of other nodes)
- **Leaves** (nodes with no children)
- **Edges** (connections between nodes)

A special type of tree used often in programming is the **Binary Tree**, where each node has at most two children.

---

## 🎯 Why Learn Trees?

Trees are fundamental in computer science. Here's why they're essential:

- 🔄 **Non-linear structure**: Ideal for representing complex relationships (e.g., hierarchy, dependencies).
- 🚀 **Efficient algorithms**: Many operations (search, insert, delete) are optimized using trees, especially in Binary Search Trees (BSTs).
- 📚 **Foundational for advanced structures**: Trees form the basis for Tries, Heaps, Segment Trees, B+ Trees, etc.
- 💡 **Helps with recursion and divide & conquer thinking**.

---

## 🧠 Real-Life Examples

| Scenario | How Trees Help |
|---------|----------------|
| **File Systems** | Directories and files are stored as trees with folders as parent nodes. |
| **Organization Chart** | Employees under managers form a hierarchical structure. |
| **HTML/XML Parsing** | DOM tree represents nested HTML elements. |
| **AI Game Trees** | Game decision paths are represented as trees (e.g., chess). |
| **Databases** | B-Trees and B+ Trees are used in indexing. |
| **Routing Protocols** | Spanning trees help find optimal paths in networks. |

---

---

## Part 2: 🌲 Binary Tree Basics

A **Binary Tree** is a tree where each node has **at most two children**:
- **Left Child**
- **Right Child**

### [Tree Structure]
```cpp
Tree:
         Root
        /   \
    Child1  Child2
```

### Key Concepts:

- **Root Node**: The topmost node.
- **Children Nodes**: Directly connected nodes to a parent.
- **Leaf Nodes**: Nodes with no children.
- **Ancestors**: Nodes on the path from a node to the root.
- **Left/Right Subtree**: The subtrees to the left/right of the root.

**Binary** means every parent can have 0, 1, or 2 children.

### Recursion Strategy:

To solve a tree problem:

```cpp
solve(root){
    solve(leftSubtree);
    solve(rightSubtree);
    calculate for root;
}
```
## Part 3: 🧠 Templates & Algorithms

### 🌟 Node Structure

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
```

---

### 🔍 Depth-First Search (DFS)

Explore as far as possible down a branch before backtracking.

- Good for recursion & subtree processing.
- Traversal order depends on variant: **Preorder**, **Inorder**, **Postorder**.

---

### ✅ Preorder Traversal  
Visit: **Root → Left → Right**

```cpp
void preOrder(TreeNode* root, vector<int>& arr) {
    if (root == NULL) return;
    arr.push_back(root->val);
    preOrder(root->left, arr);
    preOrder(root->right, arr);
}
```

⏱️ Time Complexity: `O(n)`  
🧠 Space Complexity: `O(h)`

---

### ✅ Inorder Traversal  
Visit: **Left → Root → Right**

```cpp
void inOrder(TreeNode* root, vector<int>& arr) {
    if (root == NULL) return;
    inOrder(root->left, arr);
    arr.push_back(root->val);
    inOrder(root->right, arr);
}
```

---

### ✅ Postorder Traversal  
Visit: **Left → Right → Root**

```cpp
void postOrder(TreeNode* root, vector<int>& arr) {
    if (root == NULL) return;
    postOrder(root->left, arr);
    postOrder(root->right, arr);
    arr.push_back(root->val);
}
```

---

### 🌐 Level Order Traversal (BFS)  
Breadth-first approach using a `queue`.

```cpp
void level(TreeNode* root, vector<vector<int>>& arr) {
    if (root == NULL) return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        vector<int> level;
        for (int i = 0; i < n; i++) {
            TreeNode* curr = q.front(); q.pop();
            level.push_back(curr->val);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        arr.push_back(level);
    }
}
```

---

### 📏 Height (Max & Min)

```cpp
int maxDepth(TreeNode* root) {
    if (root == NULL) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int minDepth(TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL) return minDepth(root->right) + 1;
    if (root->right == NULL) return minDepth(root->left) + 1;
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}
```

---

### 🔢 Count & Sum Nodes

```cpp
int count(TreeNode* root) {
    if (root == NULL) return 0;
    return count(root->left) + count(root->right) + 1;
}

int sum(TreeNode* root) {
    if (root == NULL) return 0;
    return sum(root->left) + sum(root->right) + root->val;
}
```

---

### 🔁 Identical Trees

```cpp
bool identical(TreeNode* p, TreeNode* q) {
    if (p == NULL || q == NULL) return p == q;
    return identical(p->left, q->left) &&
           identical(p->right, q->right) &&
           p->val == q->val;
}
```

---

### 🌐 Diameter of Binary Tree

```cpp
int diameterOfBinaryTree(TreeNode* root) {
    if (root == NULL) return 0;
    int left = diameterOfBinaryTree(root->left);
    int right = diameterOfBinaryTree(root->right);
    int current = height(root->left) + height(root->right);
    return max(current, max(left, right));
}
```

---

### 🔭 Top View of Binary Tree

```cpp
void TopView(Node* root) {
    map<int, int> top;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [curr, hd] = q.front(); q.pop();
        if (top.find(hd) == top.end()) top[hd] = curr->data;
        if (curr->left) q.push({curr->left, hd - 1});
        if (curr->right) q.push({curr->right, hd + 1});
    }

    for (auto [_, val] : top) {
        cout << val << " ";
    }
}
```

---

### 🔎 Kth Smallest & Largest

```cpp
// Kth Smallest
int cnt = 0, result = -1;
void kthSmallest(TreeNode* root, int k) {
    if (root == NULL || result != -1) return;
    kthSmallest(root->left, k);
    cnt++;
    if (cnt == k) {
        result = root->val;
        return;
    }
    kthSmallest(root->right, k);
}

// Kth Largest
cnt = 0, result = -1;
void kthLargest(TreeNode* root, int k) {
    if (root == NULL || result != -1) return;
    kthLargest(root->right, k);
    cnt++;
    if (cnt == k) {
        result = root->val;
        return;
    }
    kthLargest(root->left, k);
}
```

---

### 💰 Maximum Path Sum

```cpp
int maxPath(TreeNode* root, int& maxi) {
    if (root == NULL) return 0;
    int left = max(0, maxPath(root->left, maxi));
    int right = max(0, maxPath(root->right, maxi));
    maxi = max(maxi, left + right + root->val);
    return max(left, right) + root->val;
}
```

---

### 💸 Minimum Path Sum

```cpp
int minPath(TreeNode* root, int& mini) {
    if (root == NULL) return 0;
    int left = minPath(root->left, mini);
    int right = minPath(root->right, mini);
    mini = min(mini, left + right + root->val);
    return min(0, min(left, right)) + root->val;
}
```

---

## 🧾 Summary

This section provides essential theory, reusable code patterns, and hands-on C++ implementations to **master trees and binary tree algorithms** for technical interviews, coding challenges, or academic coursework.


