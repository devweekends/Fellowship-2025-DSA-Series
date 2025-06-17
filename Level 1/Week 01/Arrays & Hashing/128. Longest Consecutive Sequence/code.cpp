/*
Approach:

To find the length of the longest consecutive elements sequence in an unsorted array:

1. Insert all elements into an unordered_set for O(1) average-time lookups.
2. Iterate through each number in the set:
   - Only start counting if the current number is the beginning of a sequence (i.e., num - 1 is not in the set).
   - Then expand the sequence by checking for num + 1, num + 2, and so on.
3. Track the length of the current streak using a counter.
4. Update `longest` with the maximum of current streak and previous longest.

Note:
- This is the optimal approach using hashing.
- It avoids sorting and ensures linear time complexity.

Time Complexity:
- O(n) on average, due to set insertions and lookups.

Space Complexity:
- O(n) for storing the set.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longest = max(longest, currentStreak);
            }
        }

        return longest;
    }
};
