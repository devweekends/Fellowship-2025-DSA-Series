
# 🧱 Stack Data Structure - Complete Notes & Guide

## 📘 Definition

**Stack** is a linear data structure that works on the principle of **LIFO** (Last In First Out).

---

## ✅ When to Use Stack

| Use Case                | Why Stack is Best                          |
|------------------------|--------------------------------------------|
| Reversing order        | LIFO nature                                |
| Matching nested items  | Like parentheses, tags                     |
| Backtracking           | E.g., Undo/Redo                            |
| Expression parsing     | Evaluating expressions using operators     |
| Memory management      | Function calls are stored in call stack    |
| Monotonic logic        | Maintaining increasing/decreasing sequences|

---

## 🔧 Stack Operations

| Operation | Syntax       | Description                 |
|----------|--------------|-----------------------------|
| Push     | `st.push(x)` | Add element to top          |
| Pop      | `st.pop()`   | Remove top element          |
| Top      | `st.top()`   | View top element            |
| Size     | `st.size()`  | Number of elements          |
| Empty    | `st.empty()` | Check if stack is empty     |

---

## 🚀 Snippets

```cpp
stack<int> st;
st.push(x);
st.pop();
int top = st.top();
bool isEmpty = st.empty();
```

**Pattern: Matching Parentheses**

```cpp
if (c == '(' || c == '{' || c == '[') st.push(c);
else {
    if (st.empty() || st.top() != expected) return false;
    st.pop();
}
```

---

## 🧱 Stack Implementation

### 1. Stack Using Arrays

- Efficient cache usage
- Fixed/resizable size

```cpp
class Stack {
private:
    int* arr;
    int capacity;
    int topIndex;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    void push(int x) {
        if (topIndex == capacity - 1) {
            cout << "Overflow\n";
            return;
        }
        arr[++topIndex] = x;
    }

    void pop() {
        if (topIndex == -1) {
            cout << "Underflow\n";
            return;
        }
        topIndex--;
    }

    int top() {
        return topIndex == -1 ? -1 : arr[topIndex];
    }

    bool isEmpty() { return topIndex == -1; }

    int size() { return topIndex + 1; }

    ~Stack() { delete[] arr; }
};
```

#### 🔁 Doubling Capacity

```cpp
void doubleCapacity() {
    int* newArr = new int[2 * capacity];
    for (int i = 0; i <= topIndex; i++)
        newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
    capacity *= 2;
}
```

---

### 2. Stack Using Linked List

- Dynamically sized
- No wasted memory

```cpp
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* head;
    int count;

public:
    Stack() : head(nullptr), count(0) {}

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        count++;
    }

    void pop() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
    }

    int top() {
        return head ? head->data : -1;
    }

    bool isEmpty() { return head == nullptr; }

    int size() { return count; }

    ~Stack() {
        while (head) pop();
    }
};
```

---

## 📊 Array vs Linked List Stack

| Feature         | Array Stack     | Linked List Stack |
|----------------|------------------|-------------------|
| Resizable      | Manual / vector | Automatic         |
| Memory         | Fixed upfront   | Per node          |
| Overflow       | Yes             | No                |
| Speed          | Faster access   | Slower            |
| Code Complexity| Easier          | More complex      |

---

## 🔁 Template Code Patterns

### Increasing Stack (Next Smaller Element)
```cpp
for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] > arr[i]) {
        st.pop();
    }
    st.push(i);
}
```

### Decreasing Stack (Next Greater Element)
```cpp
for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] < arr[i]) {
        st.pop();
    }
    st.push(i);
}
```

---

## 🔣 Expression Conversions Using Stack

### Infix to Prefix

```cpp
string infixToPrefix(string s) {
    reverse(s.begin(), s.end());
    for (char &c : s) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    string postfix = infixToPostfix(s);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}
```

### Postfix to Infix

```cpp
string postfixToInfix(string s) {
    stack<string> st;
    for (char c : s) {
        if (isalnum(c)) st.push(string(1, c));
        else {
            string b = st.top(); st.pop();
            string a = st.top(); st.pop();
            st.push("(" + a + c + b + ")");
        }
    }
    return st.top();
}
```

### Postfix to Prefix

```cpp
string postfixToPrefix(string s) {
    stack<string> st;
    for (char c : s) {
        if (isalnum(c)) st.push(string(1, c));
        else {
            string b = st.top(); st.pop();
            string a = st.top(); st.pop();
            st.push(c + a + b);
        }
    }
    return st.top();
}
```

### Prefix to Postfix

```cpp
string prefixToPostfix(string s) {
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (isalnum(s[i])) st.push(string(1, s[i]));
        else {
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();
            st.push(a + b + s[i]);
        }
    }
    return st.top();
}
```

### Prefix to Infix

```cpp
string prefixToInfix(string s) {
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--) {
        char c = s[i];
        if (isalnum(c)) st.push(string(1, c));
        else {
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();
            st.push("(" + a + c + b + ")");
        }
    }
    return st.top();
}
```

---

## 🧠 Edge Cases

| Scenario                | Problem         | Fix                        |
|-------------------------|----------------|-----------------------------|
| Overflow                | Array full      | Resize / error message      |
| Underflow               | Popping empty   | Check before pop            |
| Memory leak             | Unfreed memory  | Delete in destructor        |
| Top from empty stack    | Undefined       | Return sentinel like -1     |
| Thread safety           | Unsafe          | Use mutex / atomic ops      |

---

## 🏁 Summary

- Stack is essential for recursive calls, expression evaluations, and parsing.
- Can be implemented using arrays (static/dynamic) or linked lists.
- Mastering stack patterns is crucial for many coding problems.

