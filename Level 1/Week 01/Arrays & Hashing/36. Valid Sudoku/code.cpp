/*
Approach:

To validate a Sudoku board, we ensure that:
1. Each row contains unique digits (excluding '.').
2. Each column contains unique digits.
3. Each 3x3 sub-box (square) contains unique digits.

To achieve this:
- We use three data structures:
  - `rows`: maps each row index to a set of seen digits.
  - `cols`: maps each column index to a set of seen digits.
  - `squares`: maps each 3x3 sub-grid (identified by its row/3 and col/3) to a set of seen digits.

Algorithm Steps:
1. Iterate over each cell in the 9x9 board.
2. Skip the cell if it contains `.`.
3. Compute the square key as a pair `(r / 3, c / 3)`.
4. Check if the digit already exists in the corresponding row, column, or square set.
   - If yes, return false as the board is invalid.
5. Otherwise, insert the digit into its respective row, column, and square set.
6. If no duplicates are found during the iteration, return true.

Time Complexity: O(1) — The board is always 9x9, so it's constant time.
Space Complexity: O(1) — Maximum space usage is bounded by the fixed board size.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>> squares;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;

                pair<int, int> squareKey = {r / 3, c / 3};

                if (rows[r].count(board[r][c]) || 
                    cols[c].count(board[r][c]) || 
                    squares[squareKey].count(board[r][c])) {
                    return false;
                }

                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                squares[squareKey].insert(board[r][c]);
            }
        }

        return true;
    }
};
