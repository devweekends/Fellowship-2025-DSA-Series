class Solution {
private:
    vector<vector<string>> result;
    
    // Helper function to check if placing queen at (row, col) is valid
    bool isValid(vector<string>& board, int row, int col, int n) {
        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        
        // Check upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        // Check upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        return true;
    }
    
    void backtrack(vector<string>& board, int row, int n) {
        // Base case: if we've placed queens in all rows
        if (row >= n) {
            result.push_back(board);
            return;
        }
        
        // Try placing queen in each column of current row
        for (int col = 0; col < n; col++) {
            // Check if position is valid
            if (isValid(board, row, col, n)) {
                // Make choice: place queen
                board[row][col] = 'Q';
                
                // Recurse to next row
                backtrack(board, row + 1, n);
                
                // Backtrack: remove queen
                board[row][col] = '.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        // Initialize empty board
        vector<string> board(n, string(n, '.'));
        
        backtrack(board, 0, n);
        return result;
    }
};

/*
Time Complexity: O(n!) where n is the board size
Space Complexity: O(n) for recursion stack
*/ 