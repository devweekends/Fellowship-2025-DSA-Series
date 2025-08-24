/*
Problem: 200. Number of Islands

This is a classic graph problem that can be solved using DFS or BFS.
Key insights:
1. Each island is a connected component of land cells
2. We can use DFS to explore and mark all connected land cells
3. We count the number of times we start a new DFS exploration
4. We mark visited cells to avoid counting them again

Time Complexity: O(m * n) - we visit each cell at most once
Space Complexity: O(m * n) - recursion stack depth in worst case
*/

#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        // Iterate through each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If we find a land cell, start DFS to explore the island
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;  // Increment island count
                }
            }
        }
        
        return count;
    }
    
private:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Base case: out of bounds or water cell
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == '0') {
            return;
        }
        
        // Mark current cell as visited (change to water)
        grid[row][col] = '0';
        
        // Explore all four directions
        dfs(grid, row + 1, col);  // down
        dfs(grid, row - 1, col);  // up
        dfs(grid, row, col + 1);  // right
        dfs(grid, row, col - 1);  // left
    }
};
