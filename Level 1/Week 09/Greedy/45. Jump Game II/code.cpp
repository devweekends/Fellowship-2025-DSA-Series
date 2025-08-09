/*
Approach: Greedy Algorithm

The greedy approach is to always jump to the position that allows us to reach the farthest.
We keep track of the current jump's range and the farthest position we can reach.
When we reach the end of the current jump's range, we make another jump.

Algorithm:
1. Track the farthest position reachable and current jump boundary
2. For each position, update the farthest reachable position
3. When we reach the current jump boundary, increment jumps and update boundary
4. Continue until we can reach the last index

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums)
    {
        int n = nums.size();

        if (n <= 1)
        {
            return 0;
        }

        int jumps = 0;
        int farthest = 0;
        int currentEnd = 0;

        for (int i = 0; i < n - 1; i++)
        {
            farthest = max(farthest, i + nums[i]);

            if (i == currentEnd)
            {
                ++jumps;
                currentEnd = farthest;

                if (currentEnd >= n - 1)
                {
                    break;
                }
            }
        }

        return jumps;
    }
};
