# 🚀 Two Pointers Technique

Two Pointers is a powerful algorithmic technique used primarily for **searching**, **optimizing**, or **modifying** data structures such as arrays, strings, and linked lists.

Also known as:
- Slow and Fast Pointer
- Left and Right Pointer
- Front and Back Pointer

## 🌍 Real-Life Analogies

### Two Pointers

Think of two people reading a book from opposite ends:
- One starts from the beginning (left), the other from the end (right).
- They meet in the middle and compare notes.
- Useful when trying to find a "match" or "balance" between two sides.
---

## 🧠 When To Use Two Pointers?

| Scenario                            | Why Two Pointers?                                           |
|-------------------------------------|-------------------------------------------------------------|
| Pair problems in a sorted array     | Enables linear time search (e.g., `Two Sum II`)             |
| Reversing elements                  | Efficiently swap from both ends                             |
| Checking palindromes                | Compare elements from both sides                            |
| Merging, partitioning               | Traverse from both ends and make decisions                  |
| Removing/Skipping elements          | Maintain positions with two indices                         |

---

## ✅ Ideal Situations

- The input is **sorted**
- You need to **find or compare pairs/triplets**
- You want to **optimize time complexity** from `O(n^2)` to `O(n)`
- You are doing **in-place modifications**

---

## 🔄 Pointer Types

### 1. **Converging Pointers**  
Move from both ends toward the center.  
**Use case:** Pair sum, reverse string, palindrome check.

### 2. **Parallel Pointers**  
Two pointers moving at different speeds.  
**Use case:** Cycle detection, middle of linked list.

### 3. **Triggered Pointers**  
One pointer moves when a condition is met.  
**Use case:** Move zeroes, remove duplicates.

---

## 🔧 Common Patterns & Code Snippets

### 🔁 Meet in the Middle – Pair Sum

```cpp
int left = 0, right = arr.size() - 1;
while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == target) return true;
    else if (sum < target) left++;
    else right--;
}

## 🔄 Reverse Elements In-place

Use this pattern to reverse strings, arrays, or any linear structure **in-place** using two pointers.

```cpp
int left = 0, right = s.length() - 1;
while (left < right) {
    swap(s[left++], s[right--]);
}

```
## 🚢 Move Based on Condition – Partition Logic

Common in problems like **Boats to Save People**, where you're partitioning based on weight/condition.

```cpp
sort(arr.begin(), arr.end());
int left = 0, right = arr.size() - 1, count = 0;
while (left <= right) {
    if (arr[left] + arr[right] <= limit) left++;
    right--;
    count++;
}
```

---

## 🧩 Linked List – Two Pointers

### 1. Find Middle of a Linked List

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

### 2. Detect Cycle in Linked List

```cpp
bool hasCycle(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
```

### 3. Find Start of Cycle

```cpp
ListNode* detectCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (!fast || !fast->next) return nullptr;
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
```

### 4. Reverse a Linked List

```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
```

### 5. Check Palindrome in Linked List

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
        ListNode* tmp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = tmp;
    }

    ListNode* left = head, *right = prev;
    while (right) {
        if (left->val != right->val) return false;
        left = left->next;
        right = right->next;
    }
    return true;
}
```

### 6. Remove N-th Node from End

```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* fast = dummy, *slow = dummy;
    for (int i = 0; i < n; ++i) fast = fast->next;
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}
```

---

## 🧵 Memorization Snippets

```cpp
// Two pointers loop:
while (left < right) {
    // Your logic here
}

// Reverse an array:
while (i < j) swap(arr[i++], arr[j--]);

// Pair sum logic:
if (arr[i] + arr[j] < target) i++;
else if (arr[i] + arr[j] > target) j--;
else return true;
```

---

## 📌 Final Tips

- ✅ Always check if the array is sorted (or sort it)
- 🔁 Use `left < right` unless using overlapping pointers
- ⛔ Avoid nested loops — aim for **O(n)** or **O(n log n)**
- 👀 Think in terms of how the two pointers move and interact
- 💡 Works well for space-optimized solutions with constant space