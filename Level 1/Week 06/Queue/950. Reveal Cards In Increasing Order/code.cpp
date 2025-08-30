#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


/*
Approach 1:
--------

Sort the Deck
Since the goal is to reveal the cards in increasing order, the first step is to sort the input deck.
For example, if the deck is [17,13,11,2,3,5,7], the sorted version would be [2,3,5,7,11,13,17].

The Reverse Simulation Method
Trying to simulate the card-revealing process forwards to find the correct initial order is difficult. It is much easier to work backward from the final, sorted state.
The steps for this reverse process are:
Start with an empty list or deque.
Take the largest card from your sorted list and place it into your empty list.
Now, for every subsequent card (working from largest to smallest), first take the last element currently in your list and move it to the front. Then, add the new card to the front.


Final Result
After you have placed all the cards from the sorted list back into the new list using this method, the resulting order is the correct initial deck arrangement that satisfies the problem's conditions.

Example 
Let's use the sorted deck: [2,3,5,7,11,13,17]. We will work backward from 17 down to 2.
Start with an empty list: []
Insert 17: [17]
Move the last element (17) to the front, then insert 13 at the front: [13,17]
Move the last element (17) to the front, then insert 11 at the front: [11,17,13]
Move the last element (13) to the front, then insert 7 at the front: [7,13,11,17]
Move the last element (17) to the front, then insert 5 at the front: [5,17,7,13,11]
Move the last element (11) to the front, then insert 3 at the front: [3,11,5,17,7,13]
Move the last element (13) to the front, then insert 2 at the front: [2,13,3,11,5,17,7]
The final answer is [2,13,3,11,5,17,7].

Complexity Analysis
Sorting: The initial sort of the deck takes O(nlogn) time.
Reverse Simulation: We iterate through the n cards once, and each operation (adding and moving elements in a deque) takes, on average, constant time. This part of the process takes O(n) time.
Total: The overall time complexity is dominated by the sorting step, resulting in O(nlogn).


*/



class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        deque<int> dq;

        // reverse simulation 
        for (int i = deck.size() - 1; i >= 0; i--) {
            if (!dq.empty()) {
                int back_ele = dq.back();
                dq.pop_back();
                dq.push_front(back_ele);
            }

            dq.push_front(deck[i]);
        }

        // convert deque to array
        vector<int> result(dq.begin(), dq.end());

        return result;
    }
};




// Previous Approch
// 🧠 Approach 2:
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

class Solution2 {
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
