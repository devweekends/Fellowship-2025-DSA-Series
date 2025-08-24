/*
Problem: 51. N-Queens

This is a classic backtracking problem to solve the n-queens puzzle.
Key insights:
1. We place queens one by one in each row
2. For each row, we try placing a queen in each column
3. Before placing a queen, we check if it's safe (no conflicts with existing queens)
4. We check for conflicts in the same column, same diagonal, and same anti-diagonal
5. If safe, we place the queen and recursively try to place queens in the next row
6. We backtrack by removing the queen to try different positions
7. When we've placed all n queens, we add the board configuration to our result

Time Complexity: O(n!) - we try n! possible configurations
Space Complexity: O(n) - recursion stack depth + board size
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);
        
        backtrack(n, 0, board, col, diag1, diag2, result);
        return result;
    }
    
private:
    void backtrack(int n, int row, vector<string>& board, vector<bool>& col,
                   vector<bool>& diag1, vector<bool>& diag2, vector<vector<string>>& result) {
        // Base case: if we've placed all n queens
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        // Try placing a queen in each column of the current row
        for (int c = 0; c < n; c++) {
            // Check if it's safe to place a queen at (row, c)
            if (isSafe(n, row, c, col, diag1, diag2)) {
                // Place the queen
                board[row][c] = 'Q';
                col[c] = true;
                diag1[row + c] = true;
                diag2[row - c + n - 1] = true;
                
                // Recursively try to place queens in the next row
                backtrack(n, row + 1, board, col, diag1, diag2, result);
                
                // Backtrack: remove the queen
                board[row][c] = '.';
                col[c] = false;
                diag1[row + c] = false;
                diag2[row - c + n - 1] = false;
            }
        }
    }
    
    // Check if it's safe to place a queen at (row, col)
    bool isSafe(int n, int row, int col, vector<bool>& colUsed, 
                vector<bool>& diag1, vector<bool>& diag2) {
        // Check column
        if (colUsed[col]) return false;
        
        // Check diagonal (top-left to bottom-right)
        if (diag1[row + col]) return false;
        
        // Check anti-diagonal (top-right to bottom-left)
        if (diag2[row - col + n - 1]) return false;
        
        return true;
    }
};
