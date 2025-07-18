/*
------------------------------------------------------
🧠 Approach: Monotonic Stack - Largest Rectangle in Histogram
------------------------------------------------------

Problem Summary:
Given an array where each element represents the height of a histogram bar (width = 1), 
we want to find the area of the largest rectangle that can be formed.

🔍 Idea:
Use a **monotonic increasing stack** to keep track of indices of bars in non-decreasing order.
This allows us to efficiently calculate the area for every bar by treating it as the smallest (limiting) height.

🔧 Key Steps:
1. Append a `0` to the end of `heights` to forcefully flush the stack at the end.
2. Iterate through `heights`:
   - While current height is less than the height at the top of the stack:
     - Pop the stack and treat the popped height as the smallest bar in a rectangle.
     - Compute the width using the current index and the new top of the stack.
     - Update `maxArea` accordingly.
   - Push the current index to the stack.
3. Return `maxArea`.

📦 Stack stores: indices of bars

🕒 Time Complexity: O(n)
💾 Space Complexity: O(n)

*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0); // Add a dummy bar of height 0
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            // Maintain increasing stack
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                int width;
                if (st.empty()) {
                    width = i; // All previous bars are taller
                } else {
                    width = i - st.top() - 1;
                }

                int area = height * width;
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }

        return maxArea;
    }
};
