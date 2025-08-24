# 🔄 Backtracking Algorithms

**Backtracking** is a **systematic way** to search for solutions to computational problems, especially constraint satisfaction problems. It builds candidates for the solution incrementally and abandons a candidate ("backtracks") as soon as it determines that the candidate cannot possibly be completed to a valid solution.

## 1️⃣ What is Backtracking?

Backtracking is like trying all possible options step-by-step, and undoing (backtracking) when a path doesn't work.
It's essentially DFS + Undo.

### 💡 Real-life analogy:

Think of solving a maze — you walk until you hit a dead end, then back up and try a different path.
Or trying outfits before a party — you try one combination, if you don't like it, you undo and try another.

## 2️⃣ Core Idea

Choose an option.

Recursively explore.

Undo the choice (backtrack) before trying another.

## 3️⃣ Patterns in Backtracking

You can usually spot a backtracking problem if:

- You must generate all combinations/permutations.
- You must search in multiple directions (grids, graphs).
- You must find all solutions, not just one.
- There's decision at each step (pick or not pick / try all possible moves).
- Constraints like "can't reuse elements" or "visit each cell once".

### Common Patterns

**Include/Exclude**
- At each step, you decide:
  - Include the current element.
  - Exclude the current element.
- Calls recursion twice.
- Example: Subset problems.

**Pick/No Pick (Loop-based)**
- Use a loop to iterate through choices.
- Pick one, recurse, undo, continue loop.
- Example: Combination Sum, Subset with Duplicates.

**Grid Search (DFS Backtracking)**
- Explore all possible moves from a position (up, down, left, right).
- Mark visited, recurse, unmark.
- Example: Word Search, Rat in Maze.

**Permutation / Arrangement**
- Choose one unused element at each step.
- Example: Permutations, N-Queens.

## 4️⃣ Pattern Recognition Checklist

Ask yourself:

- Am I generating all possible combinations/paths?
- Do I have to explore different orders or directions?
- Do I need to undo my move after exploring it?
- Are there constraints like "no repeats" or "visit once"?

If YES → Backtracking is likely.

## 5️⃣ General Backtracking Template (Loop-based)

```cpp
void backtrack(vector<int>& nums, vector<int>& temp, int start) {
    // Base case: when a solution is found
    result.push_back(temp);

    for (int i = start; i < nums.size(); i++) {
        // Skip duplicates if needed
        if (i > start && nums[i] == nums[i - 1]) continue;

        // Choose
        temp.push_back(nums[i]);

        // Explore
        backtrack(nums, temp, i + 1); 

        // Undo choice
        temp.pop_back();
    }
}
```

## 6️⃣ Include/Exclude Template

```cpp
void backtrack(vector<int>& nums, int index, vector<int>& temp) {
    if (index == nums.size()) {
        result.push_back(temp);
        return;
    }
    
    // Include current element
    temp.push_back(nums[index]);
    backtrack(nums, index + 1, temp);
    temp.pop_back();

    // Exclude current element
    backtrack(nums, index + 1, temp);
}
```

## 7️⃣ Grid DFS Backtracking Template

```cpp
bool dfs(vector<vector<char>>& board, int r, int c, int index, string& word) {
    if (index == word.size()) return true;
    if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || 
        board[r][c] != word[index]) return false;

    char temp = board[r][c];
    board[r][c] = '#'; // mark visited

    bool found = dfs(board, r+1, c, index+1, word) ||
                 dfs(board, r-1, c, index+1, word) ||
                 dfs(board, r, c+1, index+1, word) ||
                 dfs(board, r, c-1, index+1, word);

    board[r][c] = temp; // unmark visited
    return found;
}
```

## 8️⃣ Real Examples by Pattern

- **Include/Exclude**: Subset Sum, Power Set.
- **Loop-based Pick/No Pick**: Combination Sum, Subset II.
- **Grid Search**: Word Search, Rat in Maze.
- **Permutation**: N-Queens, Letter Tile Possibilities.

## 9️⃣ Time Complexity (Typical)

- Subsets: O(2^n)
- Permutations: O(n!)
- Grid DFS: O(4^(n*m)) worst case.
- Backtracking is exponential unless pruning reduces possibilities.

## 🔟 Space Complexity

O(N) recursion depth (stack space).

Additional space if storing solutions.

## 1️⃣1️⃣ Common Mistakes

- Forgetting to undo choice → leads to wrong answers.
- Not handling duplicates properly.
- Using wrong boundary conditions in grids.
- Modifying global state without restoring.

## 1️⃣2️⃣ Mind Map for Quick Recall

```
                Backtracking
                     |
    ---------------------------------
    |               |               |
Include/Exclude  Loop-based     Grid DFS
    |               |               |
 Subsets         Comb. Sum       Word Search
 Power Set       Subset II       Rat in Maze
```

## 📋 Problems Covered

1. **[78. Subsets](./01.%20078-subsets/)** - Generate all possible subsets
2. **[39. Combination Sum](./02.%20039-combination-sum/)** - Find combinations that sum to target
3. **[40. Combination Sum II](./03.%20040-combination-sum-ii/)** - Find combinations with duplicates
4. **[46. Permutations](./04.%20046-permutations/)** - Generate all permutations
5. **[90. Subsets II](./05.%20090-subsets-ii/)** - Generate subsets with duplicates
6. **[131. Palindrome Partitioning](./06.%200131-palindrome-partitioning/)** - Partition string into palindromes
7. **[17. Letter Combinations of a Phone Number](./07.%200017-letter-combinations-of-a-phone-number/)** - Generate letter combinations
8. **[51. N-Queens](./08.%200051-n-queens/)** - Place N queens on chessboard 