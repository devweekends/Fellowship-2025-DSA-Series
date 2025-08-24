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
            // Make choice: include candidates[i]
            current.push_back(candidates[i]);
            
            // Recurse with updated target (can reuse same element)
            backtrack(candidates, current, target - candidates[i], i);
            
            // Backtrack: remove candidates[i]
            current.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        backtrack(candidates, current, target, 0);
        return result;
    }
};

/*
Time Complexity: O(k * 2^target) where k is the average length of combinations
Space Complexity: O(target) for recursion stack
*/ 