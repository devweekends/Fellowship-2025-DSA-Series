/*
Problem: 40. Combination Sum II

This is similar to Combination Sum I but with key differences:
1. Each element can only be used once
2. We need to handle duplicates in the input array
3. We skip duplicate elements at the same level to avoid duplicate combinations
4. We use backtracking with careful duplicate handling

Time Complexity: O(2^n) - we explore all possible combinations
Space Complexity: O(n) - recursion stack depth
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Sort candidates to handle duplicates properly
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
            
            // Skip duplicates at the same level to avoid duplicate combinations
            if (i > start && candidates[i] == candidates[i-1]) {
                continue;
            }
            
            // Include the current candidate
            current.push_back(candidates[i]);
            
            // Recursively try to reach the target
            // Note: we start from 'i+1' because we can't reuse elements
            backtrack(candidates, remaining - candidates[i], i + 1, current, result);
            
            // Backtrack: remove the candidate
            current.pop_back();
        }
    }
};
