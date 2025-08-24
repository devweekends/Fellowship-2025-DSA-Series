/*
Problem: 46. Permutations

This is a classic backtracking problem where we need to generate all possible permutations.
Key insights:
1. We build the permutation incrementally by choosing one element at a time
2. We use a boolean array to track which elements have been used
3. For each position, we try all unused elements
4. We backtrack by marking elements as unused and removing them from the current permutation
5. When we've used all elements, we add the complete permutation to our result

Time Complexity: O(n!) - we generate n! permutations
Space Complexity: O(n) - recursion stack depth + boolean array
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        
        backtrack(nums, used, current, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& nums, vector<bool>& used, 
                   vector<int>& current, vector<vector<int>>& result) {
        // Base case: if we've used all elements
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        // Try each element that hasn't been used yet
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                // Mark this element as used
                used[i] = true;
                
                // Add it to the current permutation
                current.push_back(nums[i]);
                
                // Recursively build the rest of the permutation
                backtrack(nums, used, current, result);
                
                // Backtrack: remove the element and mark it as unused
                current.pop_back();
                used[i] = false;
            }
        }
    }
};
