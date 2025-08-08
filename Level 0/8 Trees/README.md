# 🌳 Trees Data Structures

**Trees** are fundamental **hierarchical data structures** that form the backbone of many advanced algorithms and system designs. From file systems to AI decision trees, understanding trees is crucial for becoming a strong problem solver.

## 🌳 1. What Are Trees & Why Do We Use Them?

### 🔸 What is a Tree?

A **Tree** is a **non-linear**, **hierarchical** data structure made up of **nodes**, starting from a **root** node and branching out to **children**.

Each node:

- Holds a **value**
- Points to its **child nodes**
- Has at most **one parent** (except the root, which has none)

### 🌳 Real-Life Analogy:

Imagine a **family tree**:

- You (root)
    - Your children (nodes)
        - Their children (grandchildren)
            
            This hierarchy is *not linear* like a list or array, but branches out.
            

Another example: **file system**

- C:\ (root)
    - Users (child)
        - User1 (sub-child)
            - Documents (leaf)

---

### 🔸 Why Trees?

| Use Case | Why Tree? |
| --- | --- |
| Organizing hierarchy | File systems, HTML DOM, categories |
| Fast searching | Binary Search Trees offer O(log n) search time if balanced |
| Expression evaluation | Parse Trees / Expression Trees |
| Routing and networking | Tries and prefix trees |
| AI/Compilers | Decision Trees, Syntax Trees |

---

## 📚 2. Terminologies

| Term | Meaning |
| --- | --- |
| Node | Element of a tree |
| Root | Top-most node |
| Leaf | Node with no children |
| Parent | Node with children |
| Child | Node derived from a parent |
| Subtree | Tree under a specific node |
| Height | Max distance from node to any leaf |
| Depth | Distance from root to the node |

---

## 🧱 3. Types of Trees (Focusing on Binary Tree)

### ✅ Binary Tree

- Each node has **at most two children**
- Children usually labeled `left` and `right`

---

### ✅ Complete Binary Tree

- All levels are fully filled except possibly the **last level**, which is filled **from left to right**

---

### ✅ Perfect Binary Tree

- All levels are completely filled
- All leaves are at the **same level**

---

## 🧪 4. C++ Class for Binary Tree (From Scratch)

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = right = nullptr;
    }
};
```

---

## 🔄 5. Tree Traversal Types (DFS vs BFS)

### ✅ Depth-First Search (DFS)

You go **deep before wide** — explore one branch fully before another.

**3 Types of DFS:**

| Type | Order |
| --- | --- |
| Preorder | Root → Left → Right |
| Inorder | Left → Root → Right |
| Postorder | Left → Right → Root |

---

### ✅ Breadth-First Search (BFS)

Visit nodes **level by level**.

---

## 📌 6. DFS: Inorder Traversal (Left → Root → Right)

### ✅ Code:

```cpp
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);      // go left
    cout << root->val << " "; // visit root
    inorder(root->right);     // go right
}
```

---

### 🔍 Example Tree:

```
    1
   / \
  2   3
```

➡ Inorder: `2 1 3`

---

## 📌 7. BFS: Level Order Traversal

### ✅ Code:

```cpp
void levelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front(); q.pop();
        cout << current->val << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}
```

---

## 📦 Edge Cases

| Case | Handle How? |
| --- | --- |
| Tree is empty | Check if `root == nullptr` |
| One-node tree | No left or right, return directly |
| Skewed tree (only left/right) | Still works with standard traversals |

---

## 🔧 System Design Applications

| Use Case | Tree Structure |
| --- | --- |
| HTML rendering | DOM Tree |
| Compiler | Parse Trees |
| Network Routing | Tries / Trees |
| AI Game State Search | Game Trees |
| File System | N-ary Tree |

---

## 🧠 Advanced Tree Algorithms

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

### 🔍 Depth-First Search (DFS) Templates

#### ✅ Preorder Traversal
Visit: Root → Left → Right

```cpp
void preOrder(TreeNode* root, vector<int>& arr) {
    if (root == NULL) return;
    arr.push_back(root->val);
    preOrder(root->left, arr);
    preOrder(root->right, arr);
}
```

#### ✅ Inorder Traversal
Visit: Left → Root → Right

```cpp
void inOrder(TreeNode* root, vector<int>& arr) {
    if (root == NULL) return;
    inOrder(root->left, arr);
    arr.push_back(root->val);
    inOrder(root->right, arr);
}
```

#### ✅ Postorder Traversal
Visit: Left → Right → Root

```cpp
void postOrder(TreeNode* root, vector<int>& arr) {
    if (root == NULL) return;
    postOrder(root->left, arr);
    postOrder(root->right, arr);
    arr.push_back(root->val);
}
```

### 🌐 Level Order Traversal (BFS)

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

### 🔁 Identical Trees

```cpp
bool identical(TreeNode* p, TreeNode* q) {
    if (p == NULL || q == NULL) return p == q;
    return identical(p->left, q->left) &&
           identical(p->right, q->right) &&
           p->val == q->val;
}
```

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

## ✅ Summary Table

| Concept | Key Idea |
| --- | --- |
| Tree | Hierarchical data structure |
| Binary Tree | Max 2 children per node |
| Complete Tree | Last level filled left to right |
| Perfect Tree | All levels fully filled |
| Inorder | Left → Root → Right |
| Level Order (BFS) | Visit level-by-level |
| Class Template | `TreeNode` with `left`, `right`, and constructor |
| Use in DSA/System Design | Search, hierarchy, memory-efficient paths |

---

## 🎯 Recursion Strategy

To solve a tree problem:

```cpp
solve(root){
    solve(leftSubtree);
    solve(rightSubtree);
    calculate for root;
}
```

---

## 📊 Time & Space Complexity

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Traversal (DFS/BFS) | O(n) | O(h) - height of tree |
| Height calculation | O(n) | O(h) |
| Node count | O(n) | O(h) |
| Search in BST | O(log n) | O(h) |
| Insert/Delete in BST | O(log n) | O(h) |

---

## 🚀 Real-Life Applications

| Scenario | How Trees Help |
|-----------|----------------|
| File Systems | Directories and files are stored as trees with folders as parent nodes |
| Organization Chart | Employees under managers form a hierarchical structure |
| HTML/XML Parsing | DOM tree represents nested HTML elements |
| AI Game Trees | Game decision paths are represented as trees (e.g., chess) |
| Databases | B-Trees and B+ Trees are used in indexing |
| Routing Protocols | Spanning trees help find optimal paths in networks |

---

## 🎯 Problem-Solving Approach

1. **Identify the tree type** (Binary, BST, Complete, etc.)
2. **Choose traversal strategy** (DFS vs BFS)
3. **Handle edge cases** (null root, single node, skewed trees)
4. **Use recursion** for most tree problems
5. **Consider space complexity** (stack space for recursion)

---

## 📝 Practice Problems

The following problems are organized to build your tree-solving skills progressively:

1. **Diameter of Binary Tree** - Basic tree properties
2. **Subtree of Another Tree** - Tree comparison
3. **Lowest Common Ancestor of a BST** - BST properties
4. **Binary Tree Level Order Traversal** - BFS fundamentals
5. **Binary Tree Right Side View** - Level-based problems
6. **Count Good Nodes In Binary Tree** - Path-based problems
7. **Validate Binary Search Tree** - BST validation
8. **Kth Smallest Element in a BST** - BST traversal
9. **Construct Binary Tree From Preorder and Inorder** - Tree construction
10. **Binary Tree Maximum Path Sum** - Advanced path problems
11. **Serialize and Deserialize Binary Tree** - Tree serialization

---

## 🧠 Key Takeaways

- **Trees are hierarchical** - think in terms of parent-child relationships
- **Recursion is natural** for tree problems
- **DFS vs BFS** - choose based on problem requirements
- **Edge cases matter** - always handle null nodes
- **BST properties** - left subtree < root < right subtree
- **Path problems** - often involve tracking from root to leaf
- **Construction problems** - use traversal orders to rebuild trees

---

## 🔗 Related Topics

- **Binary Search Trees** - Ordered trees for efficient search
- **Heaps** - Complete binary trees for priority queues
- **Tries** - Tree structures for string operations
- **Segment Trees** - Trees for range queries
- **AVL Trees** - Self-balancing binary search trees
- **Red-Black Trees** - Another self-balancing tree structure

---

*Master trees, and you'll have a solid foundation for advanced data structures and algorithms!* 🌳 