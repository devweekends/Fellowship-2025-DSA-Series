/*
Problem: 90. Subsets II

This is similar to Subsets I but with duplicates in the input array.
Key insights:
1. We sort the array to group duplicates together
2. We use backtracking to generate all possible subsets
3. We skip duplicate elements at the same level to avoid duplicate subsets
4. We have two choices for each element: include it or exclude it
5. We handle duplicates carefully to ensure unique subsets

Time Complexity: O(2^n) - we generate 2^n subsets
Space Complexity: O(n) - recursion stack depth
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Sort to group duplicates together
        sort(nums.begin(), nums.end());
        
        backtrack(nums, 0, current, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
        // Base case: when we've processed all elements
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }
        
        // Choice 1: Include the current element
        current.push_back(nums[index]);
        backtrack(nums, index + 1, current, result);
        current.pop_back();  // Backtrack
        
        // Choice 2: Exclude the current element
        // Skip duplicates at the same level to avoid duplicate subsets
        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            index++;
        }
        backtrack(nums, index + 1, current, result);
    }
};
