/*
Problem: 213. House Robber II

Extension of House Robber I with circular constraint.
Key insight: Either rob houses [0...n-2] OR [1...n-1], then take maximum.
*/

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Recursion (Brute Force)
    // Time: O(2^n), Space: O(n) - recursion stack
    int robRecursion(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        // Case 1: Rob houses [0...n-2] (exclude last)
        // Case 2: Rob houses [1...n-1] (exclude first)
        int case1 = robLinearRecursion(nums, 0, n - 2);
        int case2 = robLinearRecursion(nums, 1, n - 1);
        return max(case1, case2);
    }
    
private:
    int robLinearRecursion(vector<int>& nums, int start, int end) {
        if (start > end) return 0;
        if (start == end) return nums[start];
        
        int rob = nums[start] + robLinearRecursion(nums, start + 2, end);
        int skip = robLinearRecursion(nums, start + 1, end);
        return max(rob, skip);
    }
    
public:
    // Approach 2: Memoization (Top-Down DP)
    // Time: O(n), Space: O(n) - memoization table + recursion stack
    int robMemo(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        unordered_map<int, int> memo1, memo2;
        int case1 = robLinearMemo(nums, 0, n - 2, memo1);
        int case2 = robLinearMemo(nums, 1, n - 1, memo2);
        return max(case1, case2);
    }
    
private:
    int robLinearMemo(vector<int>& nums, int index, int end, unordered_map<int, int>& memo) {
        if (index > end) return 0;
        if (memo.find(index) != memo.end()) return memo[index];
        
        int rob = nums[index] + robLinearMemo(nums, index + 2, end, memo);
        int skip = robLinearMemo(nums, index + 1, end, memo);
        memo[index] = max(rob, skip);
        return memo[index];
    }
    
public:
    // Approach 3: Tabulation (Bottom-Up DP)
    // Time: O(n), Space: O(n) - DP array
    int robTabulation(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        // Case 1: Rob houses [0...n-2]
        int case1 = robLinearTabulation(nums, 0, n - 2);
        // Case 2: Rob houses [1...n-1]
        int case2 = robLinearTabulation(nums, 1, n - 1);
        return max(case1, case2);
    }
    
private:
    int robLinearTabulation(vector<int>& nums, int start, int end) {
        int len = end - start + 1;
        if (len == 1) return nums[start];
        if (len == 2) return max(nums[start], nums[start + 1]);
        
        vector<int> dp(len);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);
        
        for (int i = 2; i < len; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[start + i]);
        }
        return dp[len-1];
    }
    
public:
    // Approach 4: Space Optimization
    // Time: O(n), Space: O(1) - only variables
    int robOptimized(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        // Case 1: Rob houses [0...n-2]
        int case1 = robLinearOptimized(nums, 0, n - 2);
        // Case 2: Rob houses [1...n-1]
        int case2 = robLinearOptimized(nums, 1, n - 1);
        return max(case1, case2);
    }
    
private:
    int robLinearOptimized(vector<int>& nums, int start, int end) {
        int len = end - start + 1;
        if (len == 1) return nums[start];
        if (len == 2) return max(nums[start], nums[start + 1]);
        
        int prev2 = nums[start];
        int prev1 = max(nums[start], nums[start + 1]);
        
        for (int i = start + 2; i <= end; i++) {
            int current = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
    
public:
    // Main function - using the most optimal approach
    int rob(vector<int>& nums) {
        return robOptimized(nums);
    }
};
