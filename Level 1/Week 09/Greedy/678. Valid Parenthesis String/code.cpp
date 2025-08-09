/*
Approach: Greedy Algorithm

The greedy approach is to track the range of possible number of open parentheses.
We maintain a minimum and maximum count of open parentheses at each step.

Algorithm:
1. Track low (minimum) and high (maximum) possible open parentheses count
2. For '(': both low and high increase by 1
3. For ')': both low and high decrease by 1
4. For '*': low decreases (treat as ')'), high increases (treat as '(')
5. If high < 0, too many ')' - return false
6. Keep low >= 0 (can't have negative open parentheses)
7. At the end, check if low == 0 (balanced)

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;  // min number of "(" open
        int high = 0; // max number of "(" open

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else if (c == '*') {
                low--;  // if * -> ')'
                high++; // if * -> '('
            }

            // ')' - too many and high < 0
            if (high < 0) {
                return false;
            }

            // if low < 0 --> reset it
            low = max(low, 0);
        }

        return low == 0;
    }
};
