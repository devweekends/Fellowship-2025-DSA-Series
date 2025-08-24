/*
Problem: 130. Surrounded Regions

This problem can be solved using DFS from the boundaries.
Key insights:
1. Start DFS from all 'O' cells on the boundaries
2. Mark all 'O' cells that are connected to boundaries as safe
3. Flip all remaining 'O' cells to 'X'
4. The key insight is to work backwards from the boundaries

Time Complexity: O(m * n) - we visit each cell at most once
Space Complexity: O(m * n) - recursion stack depth
*/

#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        
        int m = board.size();
        int n = board[0].size();
        
        // DFS from all 'O' cells on the boundaries
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0, m, n);
            }
            if (board[i][n - 1] == 'O') {
                dfs(board, i, n - 1, m, n);
            }
        }
        
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j, m, n);
            }
            if (board[m - 1][j] == 'O') {
                dfs(board, m - 1, j, m, n);
            }
        }
        
        // Flip all remaining 'O' cells to 'X' and restore 'E' to 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'E') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
private:
    void dfs(vector<vector<char>>& board, int row, int col, int m, int n) {
        // Base case: out of bounds or not 'O'
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != 'O') {
            return;
        }
        
        // Mark current cell as escape (safe from being surrounded)
        board[row][col] = 'E';
        
        // Check all four directions
        dfs(board, row + 1, col, m, n);  // down
        dfs(board, row - 1, col, m, n);  // up
        dfs(board, row, col + 1, m, n);  // right
        dfs(board, row, col - 1, m, n);  // left
    }
};
