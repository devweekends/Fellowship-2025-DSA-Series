class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();        // number of rows
        int m = matrix[0].size();     // number of columns

        int low = 0;
        int high = n * m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int row = mid / m;
            int col = mid % m;

            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};


// Approach 1

// bool searchMatrix(vector<vector<int>>& matrix, int target) {
// int n = matrix.size();        // number of rows
// int m = matrix[0].size();     // number of columns

// int i = 0;
// int j = m - 1;
// while (i < n && j >= 0) {
//     if (matrix[i][j] == target) {
//         return true;
//     } else if (matrix[i][j] > target) {
//         j--; // move left
//     } else {
//         i++; // move down
//     }
// }
// return false;
// }
