/*
Approach:

This problem can be efficiently solved using a max heap (priority queue).

1. Insert all stone weights into a max heap.
2. While there are at least 2 stones in the heap:
   - Extract the two heaviest stones (top two elements).
   - If they are equal, both are destroyed (no stone added back).
   - If they are different, the lighter stone is destroyed and the heavier stone becomes (heavier - lighter).
   - Add the remaining stone back to the heap.
3. Return the weight of the last remaining stone, or 0 if no stones remain.

The max heap allows us to efficiently get the two heaviest stones in O(log n) time.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        
        // Add all stones to max heap
        for (int stone : stones) {
            maxHeap.push(stone);
        }
        
        // Continue smashing stones until at most one remains
        while (maxHeap.size() > 1) {
            int y = maxHeap.top(); maxHeap.pop(); // Heaviest stone
            int x = maxHeap.top(); maxHeap.pop(); // Second heaviest stone
            
            if (x != y) {
                // Add the remaining stone back to heap
                maxHeap.push(y - x);
            }
            // If x == y, both stones are destroyed, nothing to add back
        }
        
        // Return the last remaining stone, or 0 if none remain
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
}; 