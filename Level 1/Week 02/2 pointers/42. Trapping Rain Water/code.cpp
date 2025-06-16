/*
Approach: Two Pointer Method (Optimized)

This solution uses a two-pointer approach to calculate how much water can be trapped between the elevation bars.

Key Idea:
At any position, the water trapped depends on the minimum of the maximum height to its left and right.
Instead of precomputing those maximums using extra space, we dynamically track:
- `left_max`: the highest bar seen from the left so far
- `right_max`: the highest bar seen from the right so far

Steps:
1. Initialize two pointers: `left` at 0 and `right` at the end of the array.
2. Track the current `left_max` and `right_max`.
3. Move the pointer pointing to the shorter bar:
   - If height at `left` is less than at `right`:
     - If current height is greater than `left_max`, update `left_max`.
     - Else, water can be trapped above this bar (add `left_max - height[left]`).
     - Move `left` pointer to the right.
   - Else (height at `right` is smaller or equal):
     - If current height is greater than `right_max`, update `right_max`.
     - Else, water can be trapped above this bar (add `right_max - height[right]`).
     - Move `right` pointer to the left.
4. Continue until the two pointers meet.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int left_max = 0;
        int right_max = 0;
        int total = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    total += left_max - height[left];
                }
                left++;
            } else {
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    total += right_max - height[right];
                }
                right--;
            }
        }
        return total;
    }
};
