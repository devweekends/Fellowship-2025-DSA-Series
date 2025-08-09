class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            // If the subarray is already sorted
            if (nums[left] <= nums[right]) {
                return nums[left];
            }

            int mid = left + (right - left) / 2;
            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;

            // Check if mid is the minimum
            if (nums[mid] <= nums[prev] && nums[mid] <= nums[next]) {
                return nums[mid];
            }

            // Decide which half to search next
            if (nums[left] <= nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1; // This should not be reached if input meets constraints
    }
};