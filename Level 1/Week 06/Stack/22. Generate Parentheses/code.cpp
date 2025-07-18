/*
--------------------------------------
🧠 Approach: Iterative Stack Simulation
--------------------------------------

We are generating all combinations of well-formed parentheses using a **stack-based iterative approach**, which simulates recursion.

🔹 Key Idea:
- Use a stack to hold states, where each state contains:
  • the current string being built,
  • number of remaining open brackets,
  • number of remaining close brackets.
- Always push a `'('` if we still have open brackets left.
- Only push a `')'` if the number of remaining close brackets > open brackets (to ensure validity).
- When both `open` and `close` are 0, we have a valid combination.

📦 State in stack:
  tuple<string current, int openLeft, int closeLeft>

🕒 Time Complexity:  O(2^n) (pruned via constraints)
💾 Space Complexity: O(2^n) (result + stack space)

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        stack<tuple<string, int, int>> st;

        st.push({"", n, n});  // (current_string, open_left, close_left)

        while (!st.empty()) {
            auto [current, open, close] = st.top();
            st.pop();

            if (open == 0 && close == 0) {
                result.push_back(current);
            }

            if (open > 0) {
                st.push({current + "(", open - 1, close});
            }

            if (close > open) {
                st.push({current + ")", open, close - 1});
            }
        }

        return result;
    }
};
