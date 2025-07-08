/*
Approach: Binary Search on Flattened 2D Matrix

Problem:
- Given a 2D matrix where:
  - Integers in each row are sorted in ascending order.
  - The first integer of each row is greater than the last integer of the previous row.
- We need to determine if a given `target` exists in the matrix using O(log (m × n)) time.

Steps:

1. **Edge Case Check**:
   - If the matrix is empty (`rows == 0`), return `false`.

2. **Flatten the Matrix**:
   - Convert the 2D matrix into a 1D array called `flat` using nested loops.
   - This helps treat the 2D matrix like a simple sorted array.

3. **Apply Binary Search**:
   - Set `low = 0` and `high = flat.size() - 1`.
   - While `low <= high`:
     - Calculate `mid = (low + high) / 2`.
     - If `flat[mid] == target`: return `true`.
     - If `flat[mid] < target`: move right → `low = mid + 1`.
     - Else: move left → `high = mid - 1`.

4. **Return Result**:
   - If not found, return `false`.

Time Complexity: O(log (m × n))  
Space Complexity: O(m × n) (due to flattening into a new array)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0)
            return false;
        
        int cols = matrix[0].size();

        vector<int> flat;
        for (auto& row : matrix) {
            for (int num : row) {
                flat.push_back(num);
            }
        }

        int low = 0;
        int high = flat.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (flat[mid] == target){
                return true;
            }
            else if (flat[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
    }
};
