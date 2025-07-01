# Linked List - Complete Guide

## Introduction

Linked List is a linear data structure made up of elements called **Nodes**.  
These are not stored in contiguous memory like arrays, meaning one value might be at address 765 and the next could be anywhere.  
It helps in dynamically increasing or decreasing the size of the list.

- Starting point is called **head**
- Last node's pointer is `nullptr`, considered as the **tail**
- Navigation: `head → head->next → ...`
- Commonly used in stacks and queues due to their flexible size
- Real-life example: browser history (back/forward)

Each Node contains:

- Data
- Pointer to the next node
- Data is **not stored in contiguous memory**
- Size is **dynamic** (can grow/shrink)
- No direct access to a middle element — we **traverse from head**

---

## Universal Code Snippet

**Write this before every code that uses LL:**

```cpp
if (head == NULL) return head;
```

## Node Representation

Self-defined datatype using a constructor for reuse:

```cpp
struct ListNode {
    int data;
    ListNode* next;

    ListNode(int x) {
        data = x;
        next = nullptr;
    }
};
```

### Initialization

```cpp
Node x = new newNode(2, nullptr);
Node* y = &x; // pointer to x
```

---

## Why Use LinkedList

| Feature | Array | Linked List |
|--------|-------|-------------|
| Dynamic Size | ❌ | ✅ |
| Insert/Delete at beginning | O(n) | O(1) |
| Random Access | O(1) | O(n) |
| Memory Usage | Contiguous | Non-contiguous |

Use Linked List when:

- You don’t know the size in advance.
- Frequent insertions/removals.
- No need for random access.

---

## Traversing Linked List

### Convert Array to LL

```cpp
Node* arrayToLinkedList(const vector<int>& arr) {
    if (arr.empty()) return NULL;

    Node* head = new Node(arr[0]);
    Node* tail = head;

    for (int i = 1; i < arr.size(); ++i) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }

    return head;
}
```

### Traverse

```cpp
void Traverse(Node* head) {
    Node* temp = head;
    while (temp) {
        // process(temp->data)
        temp = temp->next;
    }
}
```

---

## Length of LL

```cpp
int length(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while (temp) {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
```

---

## Search in LL

```cpp
bool check(Node* head, int val) {
    Node* temp = head;
    while (temp) {
        if (temp->data == val) return true;
        temp = temp->next;
    }
    return false;
}
```

---

## Basic Operations

### Insert at Beginning

```cpp
ListNode* insertAtBeginning(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    return newNode;
}
```

### Insert at End

```cpp
ListNode* insertAtEnd(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);
    if (!head) return newNode;
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}
```

### Insert at K-th Position

```cpp
Node* insertK(Node* head, int cl, int k) {
    if (k < 1) return head;
    if (k == 1) return new Node(cl, head);

    Node* temp = head;
    int cnt = 1;
    while (temp && cnt < k - 1) {
        temp = temp->next;
        cnt++;
    }
    if (temp) {
        Node* newNode = new Node(cl, temp->next);
        temp->next = newNode;
    }
    return head;
}
```

---

## Delete Operations

### Delete Head

```cpp
Node* deleteHead(Node* head) {
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
```

### Delete Tail

```cpp
Node* deleteTail(Node* head) {
    if (!head || !head->next) return nullptr;
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
    return head;
}
```

### Delete K-th Node

```cpp
Node* deleteKth(Node* head, int k) {
    if (!head) return head;
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = nullptr;
    int cnt = 1;

    while (temp && cnt < k) {
        prev = temp;
        temp = temp->next;
        cnt++;
    }

    if (temp) {
        prev->next = temp->next;
        delete temp;
    }
    return head;
}
```

---

## Fast & Slow Pointers

### Find Middle

```cpp
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
```

---

## Reverse Linked List

```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }
    return prev;
}
```

---

## Detect Cycle

```cpp
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
```

---

## Remove Nth Node from End

```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* fast = dummy;
    ListNode* slow = dummy;
    for (int i = 0; i <= n; ++i) fast = fast->next;
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}
```

---

## Merge Two Sorted Lists

```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}
```

---

## Check Palindrome

```cpp
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    ListNode* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* prev = nullptr;
    while (slow) {
        ListNode* next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }
    while (prev) {
        if (head->val != prev->val) return false;
        head = head->next;
        prev = prev->next;
    }
    return true;
}
```

---

## Circular & Doubly Linked List Examples

(DLL and CLL code continues with structure and explanations as provided in original)

---

## Interview Tips

- Talk while coding: explain what and why
- Always check for `null` before accessing `.next`
- Use dummy/sentinel nodes to handle edge cases
- Prefer short helper functions (e.g., reverse, findMiddle)
- Trace on paper if stuck

---

© Educational use. Designed for coding interviews and learning.