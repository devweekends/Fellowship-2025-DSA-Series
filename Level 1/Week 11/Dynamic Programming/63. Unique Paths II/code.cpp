/*
Problem: 63. Unique Paths II

Extension of Unique Paths with obstacles. Need to handle blocked cells.
Robot cannot pass through obstacles (marked as 1).
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Approach 1: Recursion (Brute Force)
    // Time: O(2^(m+n)), Space: O(m+n) - recursion stack
    int uniquePathsWithObstaclesRecursion(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return uniquePathsRecursionHelper(0, 0, m, n, obstacleGrid);
    }
    
private:
    int uniquePathsRecursionHelper(int row, int col, int m, int n, vector<vector<int>>& grid) {
        if (row >= m || col >= n || grid[row][col] == 1) return 0;
        if (row == m - 1 && col == n - 1) return 1;
        
        int right = uniquePathsRecursionHelper(row, col + 1, m, n, grid);
        int down = uniquePathsRecursionHelper(row + 1, col, m, n, grid);
        return right + down;
    }
    
public:
    // Approach 2: Memoization (Top-Down DP)
    // Time: O(m*n), Space: O(m*n) - memoization table
    int uniquePathsWithObstaclesMemo(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        unordered_map<string, int> memo;
        return uniquePathsMemoHelper(0, 0, m, n, obstacleGrid, memo);
    }
    
private:
    int uniquePathsMemoHelper(int row, int col, int m, int n, vector<vector<int>>& grid, unordered_map<string, int>& memo) {
        if (row >= m || col >= n || grid[row][col] == 1) return 0;
        if (row == m - 1 && col == n - 1) return 1;
        
        string key = to_string(row) + "," + to_string(col);
        if (memo.find(key) != memo.end()) return memo[key];
        
        int right = uniquePathsMemoHelper(row, col + 1, m, n, grid, memo);
        int down = uniquePathsMemoHelper(row + 1, col, m, n, grid, memo);
        memo[key] = right + down;
        return memo[key];
    }
    
public:
    // Approach 3: Tabulation (Bottom-Up DP)
    // Time: O(m*n), Space: O(m*n) - 2D DP array
    int uniquePathsWithObstaclesTabulation(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        
        // Fill first row
        for (int j = 1; j < n; j++) {
            dp[0][j] = (obstacleGrid[0][j] == 1) ? 0 : dp[0][j-1];
        }
        
        // Fill first column
        for (int i = 1; i < m; i++) {
            dp[i][0] = (obstacleGrid[i][0] == 1) ? 0 : dp[i-1][0];
        }
        
        // Fill the rest
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
    
    // Approach 4: Space Optimization
    // Time: O(m*n), Space: O(n) - 1D DP array
    int uniquePathsWithObstaclesOptimized(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1) return 0;
        
        vector<int> dp(n, 0);
        dp[0] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else if (j > 0) {
                    dp[j] += dp[j-1];
                }
            }
        }
        return dp[n-1];
    }
    
    // Main function - using the most optimal approach
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return uniquePathsWithObstaclesOptimized(obstacleGrid);
    }
};
