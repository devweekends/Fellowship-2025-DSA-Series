/*
Problem: 695. Max Area of Island

This problem is similar to Number of Islands but we need to track the area of each island.
Key insights:
1. Each island is a connected component of land cells
2. We can use DFS to explore and count all connected land cells
3. We return the area from DFS and update the maximum area
4. We mark visited cells to avoid counting them again

Time Complexity: O(m * n) - we visit each cell at most once
Space Complexity: O(m * n) - recursion stack depth in worst case
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;
        
        // Iterate through each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If we find a land cell, start DFS to explore the island
                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        return maxArea;
    }
    
private:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Base case: out of bounds or water cell
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0) {
            return 0;
        }
        
        // Mark current cell as visited (change to water)
        grid[row][col] = 0;
        
        // Count current cell and explore all four directions
        int area = 1;  // Count current cell
        area += dfs(grid, row + 1, col);  // down
        area += dfs(grid, row - 1, col);  // up
        area += dfs(grid, row, col + 1);  // right
        area += dfs(grid, row, col - 1);  // left
        
        return area;
    }
};
