class Solution {
private:
    vector<vector<int>> result;
    
    void backtrack(vector<int>& nums, vector<int>& current, int start) {
        // Add current subset to result
        result.push_back(current);
        
        // Try all possible elements starting from 'start'
        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates at the same level to avoid duplicate subsets
            if (i > start && nums[i] == nums[i-1]) {
                continue;
            }
            
            // Make choice: include nums[i]
            current.push_back(nums[i]);
            
            // Recurse with next element
            backtrack(nums, current, i + 1);
            
            // Backtrack: remove nums[i]
            current.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Sort nums to handle duplicates efficiently
        sort(nums.begin(), nums.end());
        
        vector<int> current;
        backtrack(nums, current, 0);
        return result;
    }
};

/*
Time Complexity: O(2^n) where n is the length of nums
Space Complexity: O(n) for recursion stack
*/ 