// 🧠 Approach:
// This problem checks for valid matching parentheses using a **stack**.
// 1. Traverse the string character by character.
// 2. If the character is an opening bracket `(`, `{`, or `[`, push it onto the stack.
// 3. If the character is a closing bracket `)`, `}`, or `]`:
//    - Check if the stack is empty → if yes, return false (no matching opening).
//    - Otherwise, check if the top of the stack has the matching opening bracket.
//      If it doesn't match, return false.
//    - If it matches, pop the top from the stack.
// 4. After the loop, the stack must be empty for the string to be valid (all opened brackets closed).

// ✅ Time Complexity: O(n), where n = length of the string.
// ✅ Space Complexity: O(n), for the stack usage in the worst case (all characters are opening brackets).

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty() ||
                    (c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
