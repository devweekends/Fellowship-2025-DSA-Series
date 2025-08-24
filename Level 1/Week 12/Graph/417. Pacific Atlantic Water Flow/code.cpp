/*
Problem: 417. Pacific Atlantic Water Flow

This problem can be solved using DFS from the ocean boundaries.
Key insights:
1. Start DFS from Pacific Ocean boundaries (left and top edges)
2. Start DFS from Atlantic Ocean boundaries (right and bottom edges)
3. Mark cells that can reach each ocean
4. Find cells that can reach both oceans
5. Return the intersection of cells that can reach both oceans

Time Complexity: O(m * n) - we visit each cell at most once for each ocean
Space Complexity: O(m * n) - recursion stack depth
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) {
            return {};
        }
        
        int m = heights.size();
        int n = heights[0].size();
        
        // Create matrices to track which cells can reach each ocean
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        // DFS from Pacific Ocean boundaries (left and top edges)
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0, m, n);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j, m, n);
        }
        
        // DFS from Atlantic Ocean boundaries (right and bottom edges)
        for (int i = 0; i < m; i++) {
            dfs(heights, atlantic, i, n - 1, m, n);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, atlantic, m - 1, j, m, n);
        }
        
        // Find cells that can reach both oceans
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
    
private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, 
             int row, int col, int m, int n) {
        // Mark current cell as reachable
        ocean[row][col] = true;
        
        // Check all four directions
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (auto& dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            
            // Check bounds and if water can flow to current cell
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && 
                !ocean[newRow][newCol] && heights[newRow][newCol] >= heights[row][col]) {
                dfs(heights, ocean, newRow, newCol, m, n);
            }
        }
    }
};
