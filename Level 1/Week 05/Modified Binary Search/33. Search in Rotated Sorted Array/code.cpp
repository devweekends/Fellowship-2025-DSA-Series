/*
Approach: Binary Search in Rotated Sorted Array (Without Duplicates)

Problem:
- You are given a rotated sorted array and a target.
- The array was initially sorted in increasing order, but then rotated at some pivot.
- Goal: Find the index of the target using binary search in O(log n) time.

Key Observations:
- At least one half (left or right) of the array will always be **sorted**.
- Use this property to decide which half to discard at each step.

Steps:

1. **Initialize Pointers**:
   - `low = 0`, `high = nums.size() - 1`

2. **Binary Search Loop** (`while low <= high`):
   - Calculate mid: `mid = (low + high) / 2`

3. **Check for Target**:
   - If `nums[mid] == target`: return `mid`

4. **Check Which Half is Sorted**:
   - If `nums[low] <= nums[mid]`: Left half is sorted
     - If `target` lies within this sorted left half → search left (`high = mid - 1`)
     - Else → search right (`low = mid + 1`)
   - Else: Right half is sorted
     - If `target` lies within this sorted right half → search right (`low = mid + 1`)
     - Else → search left (`high = mid - 1`)

5. **Return -1 if Not Found**

Time Complexity: O(log n)  
- Search space is halved every iteration

Space Complexity: O(1)  
- Only constant extra space used
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[low] <= nums[mid]) {
                // Left half is sorted
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                // Right half is sorted
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
