#include <deque>
#include <vector>
#include <climits>
using namespace std;

// 🧠 Approach:
// This problem requires finding the shortest subarray with sum >= k.
// 1. Use prefix sums to efficiently calculate subarray sums.
// 2. Use a monotonic increasing deque to maintain potential starting points.
// 3. For each prefix sum, check if we can form a valid subarray ending at current position.
// 4. Remove elements from front of deque that can't be optimal starting points.
// 5. Remove elements from back of deque that are larger than current prefix sum.
// 6. Key insight: if prefix[i] - prefix[j] >= k, then prefix[i] - prefix[j+1] >= k for j+1 > j.
// 7. This means once we find a valid starting point, we can remove it from consideration.

// ✅ Time Complexity: O(n), each element is pushed and popped at most once
// ✅ Space Complexity: O(n), for the deque and prefix sums

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        
        // Calculate prefix sums
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        deque<int> dq; // Store indices of prefix sums
        int minLen = INT_MAX;
        
        for (int i = 0; i <= n; i++) {
            // Remove elements from front that can't be optimal starting points
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                minLen = min(minLen, i - dq.front());
                dq.pop_front();
            }
            
            // Remove elements from back that are larger than current prefix sum
            while (!dq.empty() && prefix[dq.back()] >= prefix[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        return minLen == INT_MAX ? -1 : minLen;
    }
}; 