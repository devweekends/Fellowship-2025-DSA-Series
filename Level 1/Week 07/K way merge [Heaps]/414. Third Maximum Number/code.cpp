/*
Approach:

We can solve this problem using a min heap to keep track of the top 3 distinct maximum numbers.

1. Use a min heap (priority_queue with greater<int>) to maintain the top 3 distinct elements.
2. Use a set to track distinct elements we've already seen.
3. For each number in the array:
   - If it's not already in our set (i.e., it's distinct), add it to both the set and heap.
   - If the heap size exceeds 3, remove the smallest element (which is the root of min heap).
4. After processing all elements:
   - If heap size is 3, return the root (third maximum).
   - If heap size is less than 3, return the root (maximum).

Time Complexity: O(n log k) where k = 3
Space Complexity: O(k) where k = 3
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        unordered_set<int> seen;
        
        for (int num : nums) {
            if (seen.find(num) == seen.end()) {
                seen.insert(num);
                minHeap.push(num);
                
                if (minHeap.size() > 3) {
                    minHeap.pop();
                }
            }
        }
        
        // If we have less than 3 distinct elements, return the maximum
        if (minHeap.size() < 3) {
            // Find the maximum from the heap
            int maxVal = minHeap.top();
            while (!minHeap.empty()) {
                maxVal = max(maxVal, minHeap.top());
                minHeap.pop();
            }
            return maxVal;
        }
        
        // Return the third maximum (root of min heap)
        return minHeap.top();
    }
}; 