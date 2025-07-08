/*
Approach: Binary Search to Find Minimum in Rotated Sorted Array

Problem:
- The array is sorted in ascending order but rotated at some pivot.
- We need to find the minimum element in O(log n) time.

Steps:

1. **Initialize Variables**:
   - Set `mini = INT_MAX` to keep track of the minimum.
   - Define `low = 0`, `high = nums.size() - 1` to represent the search boundaries.

2. **Binary Search Loop** (`while (low <= high)`):
   - Calculate `mid = low + (high - low) / 2`.
   - Update `mini = min(mini, nums[mid])` to track the smallest element so far.

3. **Check Which Half is Sorted**:
   - If `nums[low] <= nums[mid]`: the **left half** is sorted.
     - The minimum could be at `nums[low]`, so update `mini = min(mini, nums[low])`.
     - Discard the left half → move right: `low = mid + 1`.
   - Else: the **right half** is unsorted (so the min is in the left half).
     - Move left: `high = mid - 1`.

4. **Return Result**:
   - After the loop, return the minimum value found.

Time Complexity: O(log n)  
Space Complexity: O(1)  
(Only a few variables are used and the search space is halved each iteration)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX ;
        int low = 0 ;
        int high =  nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2 ;

            if(nums[mid] < mini)
                mini = nums[mid] ;
            
            if(nums[low] <= nums[mid]){
                mini = min(nums[low], mini) ;
                low = mid + 1;
            }
            else
                high = mid - 1 ;
        }
        return mini; 
    }
};
