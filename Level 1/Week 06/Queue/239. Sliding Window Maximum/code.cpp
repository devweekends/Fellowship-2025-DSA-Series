#include <deque>
#include <vector>
using namespace std;

// 🧠 Approach:
// This problem requires finding the maximum in each sliding window efficiently.
// 1. Use a monotonic decreasing deque to maintain potential maximum candidates.
// 2. The deque stores indices, not values, to handle window boundaries.
// 3. For each element, remove smaller elements from the back of deque (they can't be max).
// 4. Add the current element's index to the back of deque.
// 5. Remove elements from front that are outside the current window.
// 6. The front of deque always contains the index of the maximum in current window.
// 7. Key insight: maintain a decreasing sequence of indices in the deque.

// ✅ Time Complexity: O(n), each element is pushed and popped at most once
// ✅ Space Complexity: O(k), for the deque

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq; // Store indices, not values
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove elements from back that are smaller than current element
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            // Add current element's index
            dq.push_back(i);
            
            // Remove elements from front that are outside the window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // Add maximum to result (starting from k-1)
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
}; 