/*
Problem: 509. Fibonacci Number

This classic DP problem demonstrates all four approaches clearly.
Each approach builds upon the previous one, showing the evolution of optimization.
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Approach 1: Recursion (Brute Force)
    // Time: O(2^n), Space: O(n) - recursion stack
    int fibRecursion(int n) {
        if (n <= 1) return n;
        return fibRecursion(n - 1) + fibRecursion(n - 2);
    }
    
    // Approach 2: Memoization (Top-Down DP)
    // Time: O(n), Space: O(n) - memoization table + recursion stack
    int fibMemo(int n) {
        unordered_map<int, int> memo;
        return fibMemoHelper(n, memo);
    }
    
private:
    int fibMemoHelper(int n, unordered_map<int, int>& memo) {
        if (n <= 1) return n;
        if (memo.find(n) != memo.end()) return memo[n];
        memo[n] = fibMemoHelper(n - 1, memo) + fibMemoHelper(n - 2, memo);
        return memo[n];
    }
    
public:
    // Approach 3: Tabulation (Bottom-Up DP)
    // Time: O(n), Space: O(n) - DP array
    int fibTabulation(int n) {
        if (n <= 1) return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    
    // Approach 4: Space Optimization
    // Time: O(n), Space: O(1) - only two variables
    int fibOptimized(int n) {
        if (n <= 1) return n;
        int prev2 = 0, prev1 = 1;
        for (int i = 2; i <= n; i++) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
    
    // Main function - using the most optimal approach
    int fib(int n) {
        return fibOptimized(n);
    }
};
