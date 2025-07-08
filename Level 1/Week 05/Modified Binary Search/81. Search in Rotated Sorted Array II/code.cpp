/*
Approach: Binary Search in Rotated Sorted Array with Duplicates

Problem:
- You are given a rotated sorted array that may contain **duplicate elements**.
- You need to determine whether a target exists in this array.
- Goal: Do this in better than linear time if possible (though duplicates can degrade to O(n)).

Why it's challenging:
- Duplicates can make it difficult to determine which half is sorted, especially when `nums[low] == nums[mid] == nums[high]`.

Steps:

1. **Initialize Pointers**:
   - `low = 0`, `high = nums.size() - 1`

2. **Binary Search Loop** (`while low <= high`):
   - Calculate `mid = (low + high) / 2`

3. **Check for Target**:
   - If `nums[mid] == target`: return `true`

4. **Handle Duplicates**:
   - If `nums[low] == nums[mid] && nums[mid] == nums[high]`:
     - Cannot determine which half is sorted → skip both ends by doing `low++` and `high--`

5. **Determine Which Half is Sorted**:
   - If `nums[low] <= nums[mid]`: Left half is sorted
     - If `target` is in the left half: move `high = mid - 1`
     - Else: move `low = mid + 1`
   - Else: Right half is sorted
     - If `target` is in the right half: move `low = mid + 1`
     - Else: move `high = mid - 1`

6. **Return False if Not Found**

Time Complexity:  
- **Worst case**: O(n), when duplicates make it impossible to discard half  
- **Best/average case**: O(log n), when halves can be confidently identified

Space Complexity: O(1)  
- No extra space is used apart from variables
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return true;

            // Ambiguity due to duplicates
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }
            // Left half is sorted
            else if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } 
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
