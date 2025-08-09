/*
Problem: 322. Coin Change

Classic unbounded knapsack problem where we want to minimize the number of coins.
We can use each coin infinite times.
*/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    // Approach 1: Recursion (Brute Force)
    // Time: O(S^n) where S is amount, Space: O(S) - recursion stack
    int coinChangeRecursion(vector<int>& coins, int amount) {
        int result = coinChangeRecursionHelper(coins, amount);
        return result == INT_MAX ? -1 : result;
    }
    
private:
    int coinChangeRecursionHelper(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;
        
        int minCoins = INT_MAX;
        for (int coin : coins) {
            int subResult = coinChangeRecursionHelper(coins, amount - coin);
            if (subResult != INT_MAX) {
                minCoins = min(minCoins, subResult + 1);
            }
        }
        return minCoins;
    }
    
public:
    // Approach 2: Memoization (Top-Down DP)
    // Time: O(S * n), Space: O(S) - memoization table + recursion stack
    int coinChangeMemo(vector<int>& coins, int amount) {
        unordered_map<int, int> memo;
        int result = coinChangeMemoHelper(coins, amount, memo);
        return result == INT_MAX ? -1 : result;
    }
    
private:
    int coinChangeMemoHelper(vector<int>& coins, int amount, unordered_map<int, int>& memo) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;
        if (memo.find(amount) != memo.end()) return memo[amount];
        
        int minCoins = INT_MAX;
        for (int coin : coins) {
            int subResult = coinChangeMemoHelper(coins, amount - coin, memo);
            if (subResult != INT_MAX) {
                minCoins = min(minCoins, subResult + 1);
            }
        }
        memo[amount] = minCoins;
        return minCoins;
    }
    
public:
    // Approach 3: Tabulation (Bottom-Up DP)
    // Time: O(S * n), Space: O(S) - DP array
    int coinChangeTabulation(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
    
    // Approach 4: Space Optimization
    // Time: O(S * n), Space: O(S) - already optimal for this problem
    int coinChangeOptimized(vector<int>& coins, int amount) {
        // For this problem, tabulation is already space-optimal
        // We need to track all amounts from 0 to target
        return coinChangeTabulation(coins, amount);
    }
    
    // Main function - using the most optimal approach
    int coinChange(vector<int>& coins, int amount) {
        return coinChangeOptimized(coins, amount);
    }
};
