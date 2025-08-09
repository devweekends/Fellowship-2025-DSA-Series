/*
Problem: 746. Min Cost Climbing Stairs

At each step, we choose the minimum cost path from the previous two steps.
We can start from index 0 or 1, and need to reach beyond the last step.
*/

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Recursion (Brute Force)
    // Time: O(2^n), Space: O(n) - recursion stack
    int minCostClimbingStairsRecursion(vector<int>& cost) {
        int n = cost.size();
        return min(minCostRecursionHelper(cost, 0), minCostRecursionHelper(cost, 1));
    }
    
private:
    int minCostRecursionHelper(vector<int>& cost, int index) {
        if (index >= cost.size()) return 0;
        int oneStep = minCostRecursionHelper(cost, index + 1);
        int twoStep = minCostRecursionHelper(cost, index + 2);
        return cost[index] + min(oneStep, twoStep);
    }
    
public:
    // Approach 2: Memoization (Top-Down DP)
    // Time: O(n), Space: O(n) - memoization table + recursion stack
    int minCostClimbingStairsMemo(vector<int>& cost) {
        unordered_map<int, int> memo;
        int n = cost.size();
        return min(minCostMemoHelper(cost, 0, memo), minCostMemoHelper(cost, 1, memo));
    }
    
private:
    int minCostMemoHelper(vector<int>& cost, int index, unordered_map<int, int>& memo) {
        if (index >= cost.size()) return 0;
        if (memo.find(index) != memo.end()) return memo[index];
        
        int oneStep = minCostMemoHelper(cost, index + 1, memo);
        int twoStep = minCostMemoHelper(cost, index + 2, memo);
        memo[index] = cost[index] + min(oneStep, twoStep);
        return memo[index];
    }
    
public:
    // Approach 3: Tabulation (Bottom-Up DP)
    // Time: O(n), Space: O(n) - DP array
    int minCostClimbingStairsTabulation(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 2, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        }
        return min(dp[0], dp[1]);
    }
    
    // Approach 4: Space Optimization
    // Time: O(n), Space: O(1) - only two variables
    int minCostClimbingStairsOptimized(vector<int>& cost) {
        int n = cost.size();
        int next1 = 0, next2 = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            int current = cost[i] + min(next1, next2);
            next2 = next1;
            next1 = current;
        }
        return min(next1, next2);
    }
    
    // Main function - using the most optimal approach
    int minCostClimbingStairs(vector<int>& cost) {
        return minCostClimbingStairsOptimized(cost);
    }
};
