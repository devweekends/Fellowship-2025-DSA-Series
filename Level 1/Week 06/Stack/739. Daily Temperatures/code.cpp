/*
--------------------------------------------------
🧠 Approach: Monotonic Stack (Next Greater Element)
--------------------------------------------------

We are asked to find, for each day, how many days we have to wait until a warmer temperature.
This is a classic "Next Greater Element" problem that can be efficiently solved using a **monotonic decreasing stack**.

🔹 Intuition:
- We iterate through the `temperatures` array.
- For each temperature, we check the stack to see if the current temperature is **warmer than the one at the top index of the stack**.
- If it is, we pop that index from the stack and calculate the number of days waited (`i - previous index`).
- Push the current index onto the stack.

🔹 Why Monotonic Stack?
- The stack maintains indices in decreasing order of their temperature values.
- Ensures O(n) time by processing each index at most twice (push and pop).

📦 Stack stores: indices of unresolved days

🕒 Time Complexity:  O(n)
💾 Space Complexity: O(n)

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);  // Default all days to 0 (no warmer day found)
        stack<int> stk;  // Stack to keep indices of unresolved temperatures

        for(int i = 0; i < n; i++) {
            // Resolve all indices for which the current temperature is warmer
            while(!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                result[stk.top()] = i - stk.top();  // Calculate days waited
                stk.pop();
            }
            stk.push(i);  // Push current day's index
        }

        return result;
    }
};
