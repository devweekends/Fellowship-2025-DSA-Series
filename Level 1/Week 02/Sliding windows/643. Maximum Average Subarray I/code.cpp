/*
Approach (Sliding Window):

We want to find the maximum average of any contiguous subarray of length `k`.

⚙️ Logic:
1. Use two pointers: `left` and `right` to define the sliding window.
2. Accumulate the window sum while expanding the window with `right`.
3. Once the window size exceeds `k`, subtract `nums[left]` and move `left` forward.
4. When the window size is exactly `k`, compute the average and update the result.

✅ Time Complexity: O(n)
✅ Space Complexity: O(1)
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double window = 0;
        int left = 0;
        double averageSum = INT_MIN;
        
        for (int right = 0; right < nums.size(); right++) {
            window += nums[right];

            if (right - left + 1 > k) {
                window -= nums[left];
                left++;
            }

            if (right - left + 1 == k) {
                averageSum = max(averageSum, window / k);
            }
        }

        return averageSum;
    }
};
