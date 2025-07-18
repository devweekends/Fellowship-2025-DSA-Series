// 🧠 Approach:
// Design a stack that supports `push`, `pop`, `top`, and `getMin` in constant time (O(1)).
//
// 🔧 Key Idea:
// Use **two stacks**:
// 1. `st1`: Main stack to store all values.
// 2. `st2`: Auxiliary stack to keep track of **current minimum values**.
//
// ✅ When pushing a value:
// - Always push it to `st1`.
// - If `st2` is empty or the new value is **less than or equal** to the current minimum (`st2.top()`), also push it to `st2`.
//
// ✅ When popping:
// - If the value at the top of `st1` is equal to the top of `st2`, pop from both stacks (this means the minimum is being removed).
// - Otherwise, only pop from `st1`.
//
// ✅ `top()` returns the top of `st1`, and `getMin()` returns the top of `st2` (the current minimum).
//
// ⏱ Time Complexity:
// - All operations are O(1): `push`, `pop`, `top`, `getMin`.
// 🧠 Space Complexity: O(n)

class MinStack {

private:
    stack<int> st1;  // main stack
    stack<int> st2;  // min stack

public:
    MinStack() {}

    void push(int val) {
        st1.push(val);

        if (st2.empty() || val <= st2.top()) {
            st2.push(val);
        }
    }

    void pop() {
        if (st1.top() == st2.top()) {
            st2.pop();
        }
        st1.pop();
    }

    int top() {
        return st1.top();
    }

    int getMin() {
        return st2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
