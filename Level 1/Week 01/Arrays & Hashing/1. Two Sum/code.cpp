/*
Approach:

To find two numbers in the array that add up to the given target, we use a hash map (`unordered_map`) to store each number and its index as we iterate through the array.

1. For each number `nums[i]`, we compute its complement `a = target - nums[i]`.
2. We check if this complement `a` has already been seen (i.e., exists in the map).
   - If it exists, we return the indices of the complement and the current number.
3. If not, we store the current number and its index in the map.
4. Since the problem guarantees exactly one solution, we return an empty vector if no solution is found by the end of the loop (though this case shouldn't occur).

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int a = target - nums[i];

            if (mp.find(a) != mp.end()) {
                return {mp[a], i}; 
            }

            mp[nums[i]] = i; 
        }

        return {}; 
    }
};
