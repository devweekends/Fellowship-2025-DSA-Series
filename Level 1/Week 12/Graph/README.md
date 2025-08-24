# 🕸️ Data Structures Guide: Graph

This repository contains a comprehensive overview of **Graph** - a fundamental data structure consisting of a finite set of vertices (nodes) connected by edges, used to represent relationships between objects.

---

## 📑 Table of Contents

- [🧠 General Understanding](#-general-understanding)
- [🌍 Real-Life Analogy](#-real-life-analogy)
- [📘 Graph](#-graph)
  - [✅ Key Properties](#key-properties)
  - [💡 When to Use Graphs](#-when-to-use-graphs)
  - [🔄 Graph Traversal](#-graph-traversal)
  - [🧪 Real-World Examples](#-real-world-examples)
  - [⚠️ Best Practices](#-best-practices)
- [📚 Final Notes](#-final-notes)

---

## 🧠 General Understanding

### Graph

**Graph** is a non-linear data structure consisting of vertices (nodes) and edges that connect these vertices. Graphs are used to represent relationships between objects and are fundamental to many algorithms and applications.

---

## 🌍 Real-Life Analogy

Imagine graphs as **social networks**:

- **Vertices** are people (nodes)
- **Edges** are friendships (connections)
- **Directed edges** are one-way relationships (following someone)
- **Weighted edges** represent relationship strength
- **Paths** show how people are connected through mutual friends
- **Cycles** represent friend circles or groups

---

## 📘 Graph

Graphs are great when:
- You need to represent **relationships between objects**
- You want to model **networks or connections**
- You need to find **paths or routes**
- You want to analyze **dependencies or hierarchies**

### ✅ Key Properties

- **Vertices (Nodes)**: The fundamental units of the graph
- **Edges**: Connections between vertices
- **Directed/Undirected**: Edges with or without direction
- **Weighted/Unweighted**: Edges with or without weights
- **Cyclic/Acyclic**: Presence or absence of cycles
- **Connected/Disconnected**: Whether all nodes are reachable

---

### 💡 When to Use Graphs

| Scenario                                   | Use Graphs? | Reason                          |
|-------------------------------------------|-----------|----------------------------------|
| Social networks                           | ✅ Yes     | Model relationships between users |
| Navigation systems                        | ✅ Yes     | Find shortest paths between locations |
| Dependency management                     | ✅ Yes     | Model prerequisites and dependencies |
| Network routing                           | ✅ Yes     | Optimize data flow in networks |
| Simple linear relationships               | ❌ No      | Use arrays or linked lists instead |
| Hierarchical data only                    | ❌ No      | Use trees instead |

---

### 🔄 Graph Traversal

#### 1. **Depth-First Search (DFS)**
- Explore as far as possible along each branch
- Use recursion or stack
- Good for exploring all possibilities

#### 2. **Breadth-First Search (BFS)**
- Explore all neighbors at current depth
- Use queue data structure
- Good for finding shortest paths

#### 3. **Topological Sort**
- Order vertices in dependency order
- Only for directed acyclic graphs (DAGs)
- Used in build systems and scheduling

#### 4. **Union-Find**
- Track connected components
- Efficient for dynamic connectivity
- Used in network analysis

---

### 🧪 Real-World Examples

| Use Case            | Description                                           |
|---------------------|-------------------------------------------------------|
| Social Networks     | Facebook friends, Twitter followers, LinkedIn connections |
| Navigation          | Google Maps, GPS routing, flight paths                |
| Computer Networks   | Internet routing, network topology, packet switching |
| Game Development    | Game maps, AI pathfinding, character relationships   |
| Bioinformatics      | Protein interactions, gene networks, disease spread  |
| Recommendation Systems| Product recommendations, content suggestions         |

---

### ⚠️ Best Practices

- **Choose appropriate representation**: Adjacency matrix vs adjacency list
- **Consider traversal order**: DFS vs BFS based on problem requirements
- **Handle cycles carefully**: Detect and handle cycles appropriately
- **Optimize for your use case**: Directed vs undirected, weighted vs unweighted
- **Use appropriate algorithms**: Shortest path, minimum spanning tree, etc.
- **Consider memory usage**: Sparse vs dense graphs

---

## 📚 Final Notes

Graphs are essential for modeling complex relationships and solving network problems. They're fundamental for:

- **Algorithm Design**: Many classic algorithms use graphs
- **Network Analysis**: Social networks, computer networks, biological networks
- **Pathfinding**: Navigation, routing, game AI
- **Dependency Management**: Build systems, project scheduling
- **Interview Preparation**: Frequently asked in technical interviews

**Key Takeaways:**
- Graphs model relationships between objects
- Different traversal strategies serve different purposes
- Graph algorithms are fundamental to many applications
- Choose the right representation and algorithm for your problem
- Graphs can be directed/undirected, weighted/unweighted, cyclic/acyclic

---

## 📝 LeetCode Problems (Graph)

- [200. Number of Islands](./200.%20Number%20of%20Islands/)
- [695. Max Area of Island](./695.%20Max%20Area%20of%20Island/)
- [133. Clone Graph](./133.%20Clone%20Graph/)
- [994. Rotting Oranges](./994.%20Rotting%20Oranges/)
- [417. Pacific Atlantic Water Flow](./417.%20Pacific%20Atlantic%20Water%20Flow/)
- [130. Surrounded Regions](./130.%20Surrounded%20Regions/)
- [207. Course Schedule](./207.%20Course%20Schedule/)
- [210. Course Schedule II](./210.%20Course%20Schedule%20II/)
- [684. Redundant Connection](./684.%20Redundant%20Connection/)
- [127. Word Ladder](./127.%20Word%20Ladder/)
