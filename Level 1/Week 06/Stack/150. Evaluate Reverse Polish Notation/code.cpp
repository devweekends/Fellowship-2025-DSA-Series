// 🧠 Approach:
// This problem evaluates an arithmetic expression written in **Reverse Polish Notation (RPN)**.
// RPN means the operator comes **after** its operands. For example: ["2", "1", "+", "3", "*"] → ((2 + 1) * 3)
//
// ✅ Key Idea:
// Use a **stack** to simulate the evaluation process:
// - Traverse the input `tokens` one by one.
// - If the current token is a number → push it onto the stack.
// - If it’s an operator (+, -, *, /):
//     - Pop the top two elements from the stack.
//     - Perform the operation.
//     - Push the result back onto the stack.
//
// 🧮 Important:
// - The second popped number is the **left operand**, and the first popped is the **right operand**.
// - This matters for subtraction and division (`b - a`, `b / a`).
//
// ⏱ Time Complexity: O(n)
// - Each token is processed once.
// 🧠 Space Complexity: O(n)
// - In worst case, all operands are pushed onto the stack before any operation.

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string s : tokens) {
            if (s == "+") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b + a);
            } else if (s == "-") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b - a);
            } else if (s == "*") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b * a);
            } else if (s == "/") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b / a);
            } else {
                st.push(stoi(s));  // convert string to integer
            }
        }

        return st.top();  // final result
    }
};
