/*
Approach (Sliding Window with Monotonic Deque):

We are asked to find the maximum in every sliding window of size `k`.

🧰 What's a Deque?

A `deque` (double-ended queue) is a special data structure that allows insertion and deletion from **both the front and back** in O(1) time.

📌 We'll cover deques in depth later — for now, remember:
- You can use it like a **queue that supports popping from both ends**.
- Very useful when maintaining a window or range of elements (as in this problem).

⚙️ Logic:
1. Use a deque to store **indices** of elements in the current window.
2. Maintain the deque in **decreasing order of values** (monotonic queue).
   - Before adding a new element, remove all indices whose corresponding values are smaller than the current value → they can’t be the max anymore.
3. Remove indices from the front if they go out of the current window (`i - k`).
4. Once we reach index `i >= k - 1`, the front of the deque holds the index of the current window's maximum.

✅ Time Complexity: O(n)
   - Each element is added and removed from the deque at most once.
✅ Space Complexity: O(k) for the deque and result vector.

📌 Why This Works:
- The deque always keeps potential max elements in decreasing order.
- Ensures O(1) retrieval of the maximum in the current window.
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // Remove indices out of the current window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove all elements smaller than the current one
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Add current max to result when window size is at least k
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};
``
