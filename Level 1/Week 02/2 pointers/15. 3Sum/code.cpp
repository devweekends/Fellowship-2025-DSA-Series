/*
🧠 Approach: Two-Pointer Technique After Sorting

The goal is to find all **unique triplets** in the array that sum to 0.

🔸 Step-by-Step:

1. **Sort the array** to help us efficiently skip duplicates and use two-pointer logic.
2. Loop over each element in the array with index `i`:
   - Skip the element if it's the same as the previous one (`nums[i] == nums[i-1]`) to avoid duplicate triplets.
3. For each `i`, initialize two pointers:
   - `left = i + 1` (start just after i)
   - `right = n - 1` (end of array)
4. While `left < right`, calculate the sum:  
   `sum = nums[i] + nums[left] + nums[right]`
   - If the sum is **greater than 0**, move `right--` to reduce the sum.
   - If the sum is **less than 0**, move `left++` to increase the sum.
   - If the sum is **exactly 0**, we found a valid triplet.
     - Store it.
     - Move both pointers and **skip duplicates** on both sides to ensure unique triplets.
5. Continue the loop until all possible combinations are checked.

✅ Time Complexity: `O(n^2)` — due to the nested loop + two-pointer scan  
✅ Space Complexity: `O(1)` — excluding output list

⚠️ Note: Be cautious with duplicate values while iterating and while moving pointers after a valid triplet is found.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        for (int i = 0; i < n ; i++) {
            if(i>0 && nums[i] == nums[i-1]) continue;
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    triplets.push_back(temp);
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right &&  nums[right] == nums[left - 1])
                        right--;
                }
            }
        }
        return triplets;
    }
};