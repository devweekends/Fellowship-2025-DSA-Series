class Solution {
private:
    vector<vector<int>> result;
    
    void backtrack(vector<int>& nums, vector<int>& current, vector<bool>& used) {
        // Base case: if current permutation has all elements
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        // Try all elements for current position
        for (int i = 0; i < nums.size(); i++) {
            // Skip if element is already used
            if (used[i]) {
                continue;
            }
            
            // Make choice: use nums[i] at current position
            used[i] = true;
            current.push_back(nums[i]);
            
            // Recurse to fill next position
            backtrack(nums, current, used);
            
            // Backtrack: undo the choice
            current.pop_back();
            used[i] = false;
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        vector<bool> used(nums.size(), false);
        backtrack(nums, current, used);
        return result;
    }
};

/*
Time Complexity: O(n!) where n is the length of nums
Space Complexity: O(n) for recursion stack and used array
*/ 