/*
Problem: 62. Unique Paths

Classic 2D DP problem where robot can only move right or down.
Each cell represents number of ways to reach that position.
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Approach 1: Recursion (Brute Force)
    // Time: O(2^(m+n)), Space: O(m+n) - recursion stack
    int uniquePathsRecursion(int m, int n) {
        return uniquePathsRecursionHelper(0, 0, m, n);
    }
    
private:
    int uniquePathsRecursionHelper(int row, int col, int m, int n) {
        if (row == m - 1 && col == n - 1) return 1;
        if (row >= m || col >= n) return 0;
        
        int right = uniquePathsRecursionHelper(row, col + 1, m, n);
        int down = uniquePathsRecursionHelper(row + 1, col, m, n);
        return right + down;
    }
    
public:
    // Approach 2: Memoization (Top-Down DP)
    // Time: O(m*n), Space: O(m*n) - memoization table
    int uniquePathsMemo(int m, int n) {
        unordered_map<string, int> memo;
        return uniquePathsMemoHelper(0, 0, m, n, memo);
    }
    
private:
    int uniquePathsMemoHelper(int row, int col, int m, int n, unordered_map<string, int>& memo) {
        if (row == m - 1 && col == n - 1) return 1;
        if (row >= m || col >= n) return 0;
        
        string key = to_string(row) + "," + to_string(col);
        if (memo.find(key) != memo.end()) return memo[key];
        
        int right = uniquePathsMemoHelper(row, col + 1, m, n, memo);
        int down = uniquePathsMemoHelper(row + 1, col, m, n, memo);
        memo[key] = right + down;
        return memo[key];
    }
    
public:
    // Approach 3: Tabulation (Bottom-Up DP)
    // Time: O(m*n), Space: O(m*n) - 2D DP array
    int uniquePathsTabulation(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    
    // Approach 4: Space Optimization
    // Time: O(m*n), Space: O(n) - 1D DP array
    int uniquePathsOptimized(int m, int n) {
        vector<int> dp(n, 1);
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
    
    // Main function - using the most optimal approach
    int uniquePaths(int m, int n) {
        return uniquePathsOptimized(m, n);
    }
};
