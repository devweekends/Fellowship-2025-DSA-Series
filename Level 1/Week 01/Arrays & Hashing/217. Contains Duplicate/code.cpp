// Approach:
// We use an unordered_set to keep track of the numbers we have seen so far.
// As we iterate through the array, for each number:
// - If it already exists in the set, it means we've seen a duplicate, so we return true.
// - Otherwise, we insert the number into the set.
// If we finish iterating through the array without finding any duplicates, we return false.
// Time Complexity: O(n) where n is the number of elements in nums.
// Space Complexity: O(n) for storing elements in the set.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }
        return false; 
    }
};
