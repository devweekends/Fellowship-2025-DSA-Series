class Solution {
private:
    vector<vector<int>> result;
    
    void backtrack(vector<int>& candidates, vector<int>& current, int target, int start) {
        // Base case: if target becomes 0, we found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        // Base case: if target becomes negative, this path is invalid
        if (target < 0) {
            return;
        }
        
        // Try all candidates starting from 'start' index
        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates at the same level to avoid duplicate combinations
            if (i > start && candidates[i] == candidates[i-1]) {
                continue;
            }
            
            // Make choice: include candidates[i]
            current.push_back(candidates[i]);
            
            // Recurse with updated target (can't reuse same element, so i+1)
            backtrack(candidates, current, target - candidates[i], i + 1);
            
            // Backtrack: remove candidates[i]
            current.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sort candidates to handle duplicates efficiently
        sort(candidates.begin(), candidates.end());
        
        vector<int> current;
        backtrack(candidates, current, target, 0);
        return result;
    }
};

/*
Time Complexity: O(2^n) where n is the length of candidates
Space Complexity: O(n) for recursion stack
*/ 