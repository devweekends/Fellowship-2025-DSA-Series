// ✅ Approach: Two Pointer Technique
//
// 1. Sort the array to make it easier to apply the two-pointer strategy.
// 2. Use two pointers:
//    - l = 0 (left/start of array)
//    - r = nums.size() - 1 (right/end of array)
// 3. While l < r:
//    - If nums[l] + nums[r] < target, it means all elements from l to r-1 
//      will also form valid pairs with nums[l] (since the array is sorted).
//      So we add (r - l) to the count and move l++.
//    - If the sum is greater than or equal to target, we move r-- to try smaller values.
// 4. This avoids checking all pairs explicitly and improves efficiency.
//
// ✅ Time Complexity: O(n log n) due to sorting
// ✅ Space Complexity: O(1) — constant extra space

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size() - 1;
        int cnt = 0;
        while (l < r) {
            if (nums[l] + nums[r] < target) {
                cnt += r - l;
                l++;
            } else {
                r--;
            }
        }
        return cnt;
    }
};
