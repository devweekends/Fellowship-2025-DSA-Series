#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// 🧠 Approach:
// This problem requires working backwards from the desired result.
// 1. Sort the deck to get the desired increasing order.
// 2. Use a queue to simulate the reverse process of the card revealing.
// 3. Start with indices 0, 1, 2, ..., n-1 in a queue.
// 4. For each card in sorted order, place it at the position that would be revealed next.
// 5. The key insight is to work backwards: if we want cards revealed in order [1,2,3,4],
//    we need to place them in positions that would be revealed in that order.
// 6. Use a queue to track the positions where cards should be placed.

// ✅ Time Complexity: O(n log n), for sorting
// ✅ Space Complexity: O(n), for the queue and result array

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        
        queue<int> positions;
        for (int i = 0; i < n; i++) {
            positions.push(i);
        }
        
        vector<int> result(n);
        int cardIndex = 0;
        
        while (!positions.empty()) {
            // Place the next card at the front position
            int pos = positions.front();
            positions.pop();
            result[pos] = deck[cardIndex++];
            
            // If there are more positions, move the next one to the back
            if (!positions.empty()) {
                int nextPos = positions.front();
                positions.pop();
                positions.push(nextPos);
            }
        }
        
        return result;
    }
}; 