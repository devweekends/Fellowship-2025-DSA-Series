/*
Approach:

Use two heaps:
- Min heap for projects by capital
- Max heap for available projects by profit

At each step, move all projects affordable with current capital to the max heap, then pick the most profitable one.

Time Complexity: O(n log n + k log n)
Space Complexity: O(n)
*/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; ++i) {
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());
        priority_queue<int> maxProfit;
        int idx = 0;
        for (int i = 0; i < k; ++i) {
            while (idx < n && projects[idx].first <= w) {
                maxProfit.push(projects[idx].second);
                ++idx;
            }
            if (maxProfit.empty()) break;
            w += maxProfit.top();
            maxProfit.pop();
        }
        return w;
    }
}; 