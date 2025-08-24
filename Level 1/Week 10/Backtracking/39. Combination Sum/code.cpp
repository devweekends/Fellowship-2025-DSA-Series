/*
Problem: 39. Combination Sum

This is a classic backtracking problem where we need to find all combinations that sum to target.
Key insights:
1. We can use the same element multiple times
2. We sort candidates to avoid duplicate combinations
3. We only explore candidates that won't exceed the target
4. We use backtracking to explore all valid combinations

Time Complexity: O(k * 2^target) where k is the average length of combinations
Space Complexity: O(target) - recursion stack depth
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Sort candidates to avoid duplicate combinations
        sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, 0, current, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& candidates, int remaining, int start, 
                   vector<int>& current, vector<vector<int>>& result) {
        // Base case: if we've reached the target
        if (remaining == 0) {
            result.push_back(current);
            return;
        }
        
        // Base case: if we've exceeded the target
        if (remaining < 0) {
            return;
        }
        
        // Try each candidate starting from 'start' index
        for (int i = start; i < candidates.size(); i++) {
            // Skip if this candidate would exceed the target
            if (candidates[i] > remaining) {
                break;
            }
            
            // Include the current candidate
            current.push_back(candidates[i]);
            
            // Recursively try to reach the target
            // Note: we start from 'i' (not i+1) because we can reuse elements
            backtrack(candidates, remaining - candidates[i], i, current, result);
            
            // Backtrack: remove the candidate
            current.pop_back();
        }
    }
};
