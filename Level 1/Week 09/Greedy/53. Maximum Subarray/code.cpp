/*
Approach: Kadane's Algorithm (Greedy)

This is the classic maximum subarray problem that can be solved using Kadane's algorithm.
The greedy approach is to keep a running sum and reset it to the current element 
when it becomes negative, as a negative prefix would only decrease the sum.

Algorithm:
1. Initialize maxSum to the first element and currentMax to 0
2. For each element:
   - If currentMax is negative, start a new subarray from current element
   - Otherwise, extend the current subarray by adding current element
   - Update maxSum if currentMax is greater

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentMax = 0;

        for (int i = 0; i < nums.size(); i++){
            if (currentMax < 0){
                currentMax = nums[i];
            } else {
                currentMax = nums[i] + currentMax;
            }

            if (currentMax > maxSum){
                maxSum = currentMax;
            }
        }
        return maxSum;
    }
};
