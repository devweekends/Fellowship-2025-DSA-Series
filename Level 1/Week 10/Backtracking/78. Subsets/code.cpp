/*
Problem: 78. Subsets

This is a classic backtracking problem where we need to generate all possible subsets.
For each element, we have two choices: include it or exclude it.
We use backtracking to explore all combinations systematically.

Time Complexity: O(2^n) - we generate 2^n subsets
Space Complexity: O(n) - recursion stack depth
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
        // Base case: when we've processed all elements
        if (index == nums.size()) {
            result.push_back(current);  // Add current subset to result
            return;
        }
        
        // Choice 1: Include the current element
        current.push_back(nums[index]);
        backtrack(nums, index + 1, current, result);
        current.pop_back();  // Backtrack: remove the element
        
        // Choice 2: Exclude the current element
        backtrack(nums, index + 1, current, result);
    }
};
