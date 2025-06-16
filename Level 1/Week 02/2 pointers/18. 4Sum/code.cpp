// ✅ Approach:

// 1. First, sort the input array `nums` to simplify handling of duplicates
//    and to enable the two-pointer technique.

// 2. Use two nested loops to fix the first two numbers of the quadruplet:
//    - Outer loop (`i`) goes from 0 to n - 1
//    - Inner loop (`j`) goes from i + 1 to n - 1

// 3. For each fixed pair (nums[i], nums[j]), use two pointers:
//    - `left` starting from j + 1
//    - `right` starting from end of array (n - 1)

// 4. Compute the sum of the four numbers:
//    sum = nums[i] + nums[j] + nums[left] + nums[right]

//    - If sum < target: move `left` forward to increase the sum
//    - If sum > target: move `right` backward to decrease the sum
//    - If sum == target: it's a valid quadruplet, so store it,
//      then skip duplicate values of `left` and `right`

// 5. Skip duplicates for both i and j to avoid repeated quadruplets in the result.

// 6. Use `long long` to avoid integer overflow when summing large values.

// ⏱ Time Complexity: O(n^3)
// 📦 Space Complexity: O(1) (excluding output)


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> quad;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    long long sum =
                       (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum < target) {
                        left++;
                    } else if (sum > target) {
                       right--;
                    } else {
                        vector<int> temp = {nums[i], nums[j], nums[left],
                                            nums[right]};
                        quad.push_back(temp);
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return quad;
    }
};