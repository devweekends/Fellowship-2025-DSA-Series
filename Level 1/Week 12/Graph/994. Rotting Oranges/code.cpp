/*
Problem: 994. Rotting Oranges

This problem can be solved using BFS to simulate the rotting process.
Key insights:
1. Find all rotten oranges and add them to a queue
2. Use BFS to simulate the rotting process minute by minute
3. Track the number of minutes elapsed
4. Check if all fresh oranges become rotten
5. Return -1 if some fresh oranges remain unreachable

Time Complexity: O(m * n) - we visit each cell at most once
Space Complexity: O(m * n) - queue size in worst case
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        
        // Find all rotten oranges and count fresh oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        // If no fresh oranges, return 0
        if (fresh == 0) {
            return 0;
        }
        
        // If no rotten oranges but fresh oranges exist, return -1
        if (q.empty()) {
            return -1;
        }
        
        int minutes = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // BFS to simulate rotting process
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            
            // Process all oranges at current minute
            for (int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                // Check all four directions
                for (auto& dir : directions) {
                    int newRow = row + dir.first;
                    int newCol = col + dir.second;
                    
                    // Check bounds and if it's a fresh orange
                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && 
                        grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;  // Make it rotten
                        q.push({newRow, newCol});
                        fresh--;
                    }
                }
            }
            
            minutes++;
        }
        
        // Return -1 if some fresh oranges remain
        return fresh == 0 ? minutes : -1;
    }
};
