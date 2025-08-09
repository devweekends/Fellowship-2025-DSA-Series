/*
Approach: Greedy Algorithm

The key insight is that if the total gas is greater than or equal to total cost,
then there exists a solution. The greedy approach is to find the starting point
where we can complete the circuit.

Algorithm:
1. If total gas < total cost, return -1 (impossible)
2. Track current tank and starting station
3. If current tank becomes negative, start from next station and reset tank
4. The greedy choice: if we can't continue from current start, 
   the next valid start must be after the current position

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalTank = 0;
        int currentTank = 0;
        int startingStation = 0;

        for (int i = 0; i < n; i++) {
            totalTank += gas[i] - cost[i];
            currentTank += gas[i] - cost[i];

            if (currentTank < 0) {
                startingStation = i + 1;
                currentTank = 0;
            }
        }

        return totalTank >= 0 ? startingStation : -1;
    }
};
