/*
Approach: Binary Search to Find Median of Two Sorted Arrays

Problem:
- Given two sorted arrays `nums1` and `nums2`, find the **median** of the combined sorted array in O(log(min(n, m))) time.
- Do NOT merge the arrays (that would be O(n + m)).

Key Insight:
- Use binary search on the **smaller array** to partition both arrays such that:
  - Left halves from both arrays contain half the total elements.
  - Max of left half ≤ Min of right half → median found!

Steps:

1. **Ensure Binary Search is on the Smaller Array**:
   - Swap `nums1` and `nums2` if `nums1.size() > nums2.size()` to minimize the binary search range.

2. **Define Search Space**:
   - `low = 0`, `high = nums1.size()`
   - We are trying to find how many elements to take from `nums1` into the left half.

3. **Compute Partition Points**:
   - `mid1 = (low + high) / 2`: number of elements from `nums1` in left half
   - `mid2 = (left - mid1)`: remaining elements needed from `nums2` to complete the left half
   - `left = (n1 + n2 + 1) / 2`: total number of elements in the left half (ensures median works for both even and odd lengths)

4. **Handle Borders Using INT_MIN / INT_MAX**:
   - When partition touches array boundary, simulate out-of-bound values:
     - `l1`, `l2` (left elements of nums1, nums2) → `INT_MIN` if index invalid
     - `r1`, `r2` (right elements) → `INT_MAX` if index invalid

5. **Check for Correct Partition**:
   - If `l1 <= r2 && l2 <= r1`: correct split
     - If total number of elements is **odd**, return `max(l1, l2)`
     - If **even**, return average of `max(l1, l2)` and `min(r1, r2)`
   - Else:
     - If `l1 > r2`, move search left: `high = mid1 - 1`
     - Else, move search right: `low = mid1 + 1`

6. **Return 0** if no partition is found (this should never happen if inputs are valid)

Time Complexity: O(log(min(n1, n2)))  
Space Complexity: O(1)

Why it works:
- Partitions the arrays without merging
- Median is directly calculated from partition boundaries

*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int low = 0;
        int high = n1;
        int left = (n1 + n2 + 1) / 2;
        int n = n1 + n2;
        while (low <= high) {
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 -1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 -1 >= 0)
                l2 = nums2[mid2 - 1];
            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1)
                    return max(l1, l2);
                return ((double)(max(l1, l2)) + min(r1, r2)) / 2.0;
            } else if (l1 > l2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 0;
    }
};