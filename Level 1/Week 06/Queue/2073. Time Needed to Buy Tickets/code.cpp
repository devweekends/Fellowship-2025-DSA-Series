#include <queue>
#include <vector>
using namespace std;

// 🧠 Approach:
// This problem simulates a queue of people buying tickets with time tracking.
// 1. Use a queue to store pairs of (position, remaining_tickets) for each person.
// 2. Track time as each person takes 1 second to buy a ticket.
// 3. When a person buys a ticket, decrement their remaining tickets.
// 4. If they still have tickets, they go to the back of the queue.
// 5. If they're done (0 tickets), they leave the queue.
// 6. Continue until the person at position k finishes buying all their tickets.
// 7. The key insight is to track the target person and count time for each ticket purchase.

// ✅ Time Complexity: O(tickets[k] * n), where n is the number of people
// ✅ Space Complexity: O(n), for the queue

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int>> queue; // (position, remaining_tickets)
        
        // Initialize queue with all people
        for (int i = 0; i < tickets.size(); i++) {
            queue.push({i, tickets[i]});
        }
        
        int time = 0;
        
        while (!queue.empty()) {
            auto [position, remaining] = queue.front();
            queue.pop();
            
            time++; // 1 second to buy a ticket
            
            remaining--; // Buy one ticket
            
            if (remaining > 0) {
                // Person still has tickets, goes to back of queue
                queue.push({position, remaining});
            } else if (position == k) {
                // Target person finished buying all tickets
                break;
            }
            // If person is done and not the target, they just leave
        }
        
        return time;
    }
}; 