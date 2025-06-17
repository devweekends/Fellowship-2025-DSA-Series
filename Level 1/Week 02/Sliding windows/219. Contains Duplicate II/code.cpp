/*
Approach (Sliding Window + HashSet):

We need to check if there are any duplicate elements within a window size of `k`.

⚙️ Logic:
1. Use an unordered_set to keep track of elements in the current window.
2. Iterate through the array with a `right` pointer.
3. If `nums[right]` already exists in the set → we found a duplicate within range → return true.
4. Insert the current element into the set.
5. If window size exceeds `k`, remove the element at `left` and move `left` forward to shrink the window.

✅ Time Complexity: O(n)
✅ Space Complexity: O(k)
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (window.find(nums[right]) != window.end()) {
                return true;
            }

            window.insert(nums[right]);

            if (right - left + 1 > k) {
                window.erase(nums[left]);
                left++;
            }
        }
        return false;
    }
};
