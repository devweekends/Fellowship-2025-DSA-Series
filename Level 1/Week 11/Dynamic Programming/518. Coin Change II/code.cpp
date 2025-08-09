/*
Problem: 518. Coin Change II

Classic unbounded knapsack problem where we count the number of ways.
Unlike Coin Change I, we count combinations, not minimize coins.
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Approach 1: Recursion (Brute Force)
    // Time: O(2^(amount+coins)), Space: O(amount) - recursion stack
    int changeRecursion(int amount, vector<int>& coins) {
        return changeRecursionHelper(amount, coins, 0);
    }
    
private:
    int changeRecursionHelper(int amount, vector<int>& coins, int index) {
        if (amount == 0) return 1;
        if (amount < 0 || index >= coins.size()) return 0;
        
        // Include current coin or exclude it
        int include = changeRecursionHelper(amount - coins[index], coins, index);
        int exclude = changeRecursionHelper(amount, coins, index + 1);
        return include + exclude;
    }
    
public:
    // Approach 2: Memoization (Top-Down DP)
    // Time: O(amount * coins), Space: O(amount * coins) - memoization table
    int changeMemo(int amount, vector<int>& coins) {
        unordered_map<string, int> memo;
        return changeMemoHelper(amount, coins, 0, memo);
    }
    
private:
    int changeMemoHelper(int amount, vector<int>& coins, int index, unordered_map<string, int>& memo) {
        if (amount == 0) return 1;
        if (amount < 0 || index >= coins.size()) return 0;
        
        string key = to_string(amount) + "," + to_string(index);
        if (memo.find(key) != memo.end()) return memo[key];
        
        int include = changeMemoHelper(amount - coins[index], coins, index, memo);
        int exclude = changeMemoHelper(amount, coins, index + 1, memo);
        memo[key] = include + exclude;
        return memo[key];
    }
    
public:
    // Approach 3: Tabulation (Bottom-Up DP)
    // Time: O(amount * coins), Space: O(amount * coins) - 2D DP array
    int changeTabulation(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        
        // Base case: 0 amount can be made in 1 way (take no coins)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                // Exclude current coin
                dp[i][j] = dp[i-1][j];
                
                // Include current coin if possible
                if (j >= coins[i-1]) {
                    dp[i][j] += dp[i][j - coins[i-1]];
                }
            }
        }
        return dp[n][amount];
    }
    
    // Approach 4: Space Optimization
    // Time: O(amount * coins), Space: O(amount) - 1D DP array
    int changeOptimized(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        
        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }
        return dp[amount];
    }
    
    // Main function - using the most optimal approach
    int change(int amount, vector<int>& coins) {
        return changeOptimized(amount, coins);
    }
};
