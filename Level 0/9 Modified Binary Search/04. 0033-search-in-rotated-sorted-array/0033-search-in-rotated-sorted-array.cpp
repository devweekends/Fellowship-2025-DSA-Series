class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int pivot = 0;

        // Step 1: Find the pivot (smallest element's index)
        while (left <= right) {
            if (nums[left] <= nums[right]) {
                pivot = left;
                break;
            }

            int mid = left + (right - left) / 2;
            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;

            if (nums[mid] <= nums[prev] && nums[mid] <= nums[next]) {
                pivot = mid;
                break;
            }

            if (nums[mid] >= nums[left]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // Step 2: Do normal binary search in the correct half
        auto binarySearch = [&](int l, int r) -> int {
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (nums[mid] == target) return mid;
                else if (nums[mid] < target) l = mid + 1;
                else r = mid - 1;
            }
            return -1;
        };

        // Decide which half to search
        if (target >= nums[pivot] && target <= nums[n - 1]) {
            return binarySearch(pivot, n - 1);
        } else {
            return binarySearch(0, pivot - 1);
        }
    }
};