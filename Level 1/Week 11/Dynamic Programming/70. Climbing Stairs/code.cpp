/*
Problem: 70. Climbing Stairs

This is essentially the Fibonacci sequence where:
climbStairs(n) = climbStairs(n-1) + climbStairs(n-2)
To reach step n, we can come from step n-1 (1 step) or step n-2 (2 steps).
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Approach 1: Recursion (Brute Force)
    // Time: O(2^n), Space: O(n) - recursion stack
    int climbStairsRecursion(int n) {
        if (n <= 2) return n;
        return climbStairsRecursion(n - 1) + climbStairsRecursion(n - 2);
    }
    
    // Approach 2: Memoization (Top-Down DP)
    // Time: O(n), Space: O(n) - memoization table + recursion stack
    int climbStairsMemo(int n) {
        unordered_map<int, int> memo;
        return climbStairsMemoHelper(n, memo);
    }
    
private:
    int climbStairsMemoHelper(int n, unordered_map<int, int>& memo) {
        if (n <= 2) return n;
        if (memo.find(n) != memo.end()) return memo[n];
        memo[n] = climbStairsMemoHelper(n - 1, memo) + climbStairsMemoHelper(n - 2, memo);
        return memo[n];
    }
    
public:
    // Approach 3: Tabulation (Bottom-Up DP)
    // Time: O(n), Space: O(n) - DP array
    int climbStairsTabulation(int n) {
        if (n <= 2) return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    
    // Approach 4: Space Optimization
    // Time: O(n), Space: O(1) - only two variables
    int climbStairsOptimized(int n) {
        if (n <= 2) return n;
        int prev2 = 1, prev1 = 2;
        for (int i = 3; i <= n; i++) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
    
    // Main function - using the most optimal approach
    int climbStairs(int n) {
        return climbStairsOptimized(n);
    }
};
