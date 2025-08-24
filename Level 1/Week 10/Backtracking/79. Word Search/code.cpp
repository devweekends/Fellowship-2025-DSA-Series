/*
Problem: 79. Word Search

This problem uses backtracking with DFS to search for a word in a 2D grid.
Key insights:
1. We start from each cell in the grid
2. For each cell, we try to match the first character of the word
3. If matched, we recursively search in all four directions (up, down, left, right)
4. We mark visited cells to avoid reusing them
5. We backtrack by unmarking cells when the current path doesn't lead to a solution
6. We return true if we can match the entire word

Time Complexity: O(m * n * 4^L) where L is the length of the word
Space Complexity: O(L) - recursion stack depth
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        // Try starting from each cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (backtrack(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    bool backtrack(vector<vector<char>>& board, string& word, int index, int row, int col) {
        // Base case: if we've matched the entire word
        if (index == word.length()) {
            return true;
        }
        
        // Base case: if we're out of bounds
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
            return false;
        }
        
        // Base case: if the current cell doesn't match the current character
        if (board[row][col] != word[index]) {
            return false;
        }
        
        // Mark the current cell as visited (use a special character)
        char temp = board[row][col];
        board[row][col] = '#';
        
        // Try all four directions
        bool found = backtrack(board, word, index + 1, row + 1, col) ||  // down
                     backtrack(board, word, index + 1, row - 1, col) ||  // up
                     backtrack(board, word, index + 1, row, col + 1) ||  // right
                     backtrack(board, word, index + 1, row, col - 1);    // left
        
        // Backtrack: restore the original character
        board[row][col] = temp;
        
        return found;
    }
};
