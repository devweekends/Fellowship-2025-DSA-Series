/*
Approach: Binary Search

1. **Initialize Pointers**:
   - Set `low = 0` and `high = nums.size() - 1` to define the search range.

2. **Iterative Loop**:
   - While `low <= high`, calculate the middle index: `mid = low + (high - low) / 2`.
   - Compare `nums[mid]` with the `target`.

3. **Comparison Cases**:
   - If `nums[mid] == target`: return `mid` (target found).
   - If `nums[mid] < target`: move to the right half → set `low = mid + 1`.
   - If `nums[mid] > target`: move to the left half → set `high = mid - 1`.

4. **Not Found**:
   - If the loop ends without returning, the target does not exist → return `-1`.

Time Complexity: O(log n)  
Space Complexity: O(1)  
(Because the search space is halved each iteration and only a few variables are used)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() -1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                return mid;
            } else if (nums[mid] < target){
                 low = mid +1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};
