/*
Approach: Greedy Algorithm

The key insight is that we can only use triplets that don't exceed the target in any dimension.
If any element of a triplet is greater than the corresponding target element, 
that triplet can never be part of the solution.

Algorithm:
1. Filter triplets: only consider triplets where all elements <= corresponding target elements
2. For valid triplets, track the maximum value we can achieve in each position
3. Check if we can exactly match the target in all three positions

Time Complexity: O(n) where n is the number of triplets
Space Complexity: O(1)
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> maxTriplet(3, 0);

        for (const auto& triplet : triplets) {
            // Only consider triplets that don't exceed target in any dimension
            if (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
                maxTriplet[0] = max(maxTriplet[0], triplet[0]);
                maxTriplet[1] = max(maxTriplet[1], triplet[1]);
                maxTriplet[2] = max(maxTriplet[2], triplet[2]);
            }
        }

        return (maxTriplet[0] == target[0] && 
                maxTriplet[1] == target[1] && 
                maxTriplet[2] == target[2]);
    }
};
