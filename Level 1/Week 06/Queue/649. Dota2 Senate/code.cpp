#include <queue>
#include <string>
using namespace std;

// 🧠 Approach:
// This problem simulates a voting system where senators ban each other strategically.
// 1. Use two queues to track the positions of Radiant (R) and Dire (D) senators.
// 2. Process senators in order, each senator tries to ban the next opponent.
// 3. If a senator can ban an opponent, they do so and get another turn later.
// 4. If no opponents are available to ban, that party wins.
// 5. The key insight is that each senator will ban the next opponent they encounter.
// 6. Continue until one party has no more senators to vote.

// ✅ Time Complexity: O(n), where n is the length of the senate string
// ✅ Space Complexity: O(n), for the queues

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        int n = senate.length();
        
        // Initialize queues with senator positions
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }
        
        while (!radiant.empty() && !dire.empty()) {
            int rPos = radiant.front();
            int dPos = dire.front();
            
            radiant.pop();
            dire.pop();
            
            if (rPos < dPos) {
                // Radiant senator comes first, bans Dire senator
                // Radiant senator gets another turn (add to queue with position + n)
                radiant.push(rPos + n);
            } else {
                // Dire senator comes first, bans Radiant senator
                // Dire senator gets another turn (add to queue with position + n)
                dire.push(dPos + n);
            }
        }
        
        return radiant.empty() ? "Dire" : "Radiant";
    }
}; 