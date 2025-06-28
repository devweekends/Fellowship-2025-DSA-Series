# 📦 Data Structures Guide: Arrays & Hashing

This repository contains a comprehensive overview of two fundamental data structures in computer science — **Arrays** and **Hashing**. These structures are essential for solving most algorithmic problems efficiently.

---

## 📑 Table of Contents

- [🧠 General Understanding](#-general-understanding)
- [🌍 Real-Life Analogy](#-real-life-analogy)
- [📘 Arrays](#-arrays)
  - [✅ Key Properties](#key-properties)
  - [💡 When to Use Arrays](#-when-to-use-arrays)
  - [🧪 Real-World Examples](#-real-world-examples)
  - [🔢 Array Syntax (C++)](#-array-syntax-c)
  - [⚠️ Best Practices](#-best-practices)
- [🔐 Hashing](#-hashing)
  - [⚙️ How Hashing Works](#️-how-hashing-works)
  - [💼 Applications](#-applications)
  - [🗃️ Hash Table Types](#️-hash-table-types)
    - [✅ Unordered Map](#unordered-map)
    - [🔢 Ordered Map](#ordered-map)
    - [🆚 Comparison](#comparison)
  - [📌 Use Cases](#-use-cases)
  - [⚠️ Best Practices](#️-best-practices-1)
- [📚 Final Notes](#-final-notes)

---

## 🧠 General Understanding

### Array

An **array** is a linear data structure that stores elements in **contiguous memory** locations. Each element can be accessed directly using an **index**, providing **O(1)** access time.

---

## 🌍 Real-Life Analogy

Imagine an array as a **row of mailboxes**:

- Each mailbox has a **number (index)**.
- You can directly open mailbox `n` without looking at others.
- The number of mailboxes is **fixed** unless a new row is built.

---

## 📘 Arrays

Arrays are great when:
- You know the size of the data in advance.
- You need **fast** and **random access**.
- You prefer simplicity over flexibility.

### ✅ Key Properties

- **Fixed size**
- **Contiguous memory**
- **Index-based access** (`O(1)`)
- Costly insertions/deletions (except at the end)
- Iteration is straightforward

---

### 💡 When to Use Arrays

| Scenario                                   | Use Array? | Reason                          |
|-------------------------------------------|------------|----------------------------------|
| Fast random access (`arr[5]`)             | ✅ Yes      | `O(1)` access time               |
| Known size beforehand                     | ✅ Yes      | Simple and memory efficient      |
| Frequent insert/delete in middle          | ❌ No       | Shifting is expensive            |
| Need for dynamic resizing                 | ❌ No       | Use `vector` or `ArrayList`      |

---

### 🧪 Real-World Examples

| Use Case            | Description                                           |
|---------------------|-------------------------------------------------------|
| Calendar            | 7 fixed days in a week                                |
| Exam scores         | Fixed number of students and their scores             |
| Chess board         | 2D array for 8x8 layout                               |
| RGB image data      | 3D array (height × width × color channels)            |
| Dynamic Programming | Store intermediate states in 1D/2D arrays             |

---

### 🔢 Array Syntax (C++)

```cpp
// Declaration
int arr[5];

// Initialization
int arr2[] = {1, 2, 3};

// Access
cout << arr2[1]; // Output: 2

// Traversal
for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}

// Input
for (int i = 0; i < n; i++) {
    cin >> arr[i];
}

// Size of static array
int size = sizeof(arr) / sizeof(arr[0]);
```

### ⚠️ Best Practices

- Avoid out-of-bound access → always check `i < size`.
- Use `vector` or `ArrayList` instead of raw arrays for flexibility.
- Prefer 0-based indexing for consistency across languages.
- Use `sizeof(arr)/sizeof(arr[0])` to get size in static arrays.
- Pre-initialize large arrays with `memset()` for 0/-1.
- Use multidimensional arrays for matrix/grid operations.

---

## 🔐 Hashing

Hashing is a technique used to **map data to a specific value**, often for fast access, lookup, insertion, or deletion. A **hash function** converts keys into array indices for fast operations (typically O(1) on average).

---

### ⚙️ How Hashing Works

1. A **key** is passed to a **hash function**.
2. The hash function computes a **hash code**, which maps to an **index** in an internal array (bucket).
3. If two keys map to the same index (collision), the structure resolves it via **chaining** or **open addressing**.

```text
key -> hash() -> index -> store/retrieve at table[index]

```

### 💼 Applications

- Caches (e.g., LRU cache)
- Database indexing
- Sets/Maps in programming
- Password storage (with secure hash functions)
- Symbol tables in compilers
- Duplicate detection

---

### 🗃️ Hash Table Types

#### ✅ Unordered Map

- **C++**: `unordered_map`
- **Python**: `dict`
- **Java**: `HashMap`

**Properties:**

- Average **O(1)** operations
- No guaranteed order
- Backed by **hash tables**

#### 🔢 Ordered Map

- **C++**: `map` (Red-Black Tree)
- **Java**: `TreeMap`
- **Python**: `collections.OrderedDict` (pre-3.7)

**Properties:**

- Logarithmic operations: **O(log n)**
- Maintains sorted order
- Backed by **balanced binary search trees**

---

### 🆚 Comparison

| Feature           | Unordered Map | Ordered Map         |
|------------------|----------------|----------------------|
| Speed (avg)      | O(1)           | O(log n)             |
| Maintains Order? | ❌ No           | ✅ Yes               |
| Internal Struct  | Hash Table     | Tree (e.g., AVL)     |
| Use Case         | Fast lookup    | Sorted iteration     |

---

### 📌 Use Cases

| Scenario                        | Use Hashing? | Reason                             |
|----------------------------------|--------------|------------------------------------|
| Fast search by key               | ✅ Yes        | O(1) average lookup                |
| Need to maintain key order       | ❌ No         | Use Ordered Map instead            |
| Count frequency of elements      | ✅ Yes        | Key = element, Value = count       |
| Check for existence in a set     | ✅ Yes        | Fast `contains()` operation        |
| Key-based caching                | ✅ Yes        | Fast access to stored data         |

---

### ⚠️ Best Practices (Hashing)

- Choose a **good hash function** to avoid collisions.
- Handle collisions properly (e.g., via **chaining** or **open addressing**).
- Avoid **mutable keys** (e.g., objects that change after insertion).
- Monitor **memory usage** — hash tables can be memory-intensive.
- For secure applications (e.g., passwords), use **cryptographic hash functions**.
